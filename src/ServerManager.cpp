#include "ServerManager.hpp"
#include "DataStringifier.hpp"

using namespace godot;

void ServerManager::_register_methods()
{
	register_method("_init", &ServerManager::_init);
	register_method("_ready", &ServerManager::_ready);
	register_method("_process", &ServerManager::_process);

	register_method("OnDataReceived", &ServerManager::OnDataReceived);
	
	register_method("OnClientConnected", &ServerManager::OnClientConnected);
	register_method("OnClientDisconnected", &ServerManager::OnClientDisconnected);
	register_method("OnPingTimerTimeout", &ServerManager::OnPingTimerTimeout);
	register_method("GetLastSendedPingTime", &ServerManager::GetLastSendedPingTime);


}
void ServerManager::_ready()
{
	pingTimer = Timer()._new();
	pingTimer->set_wait_time(0.5);
	pingTimer->set_one_shot(false);
	pingTimer->connect("timeout", this, "OnPingTimerTimeout");
	add_child(pingTimer);
	pingTimer->start();

}
void ServerManager::_init()
{
	server.instance();
	CreateServer();
	//SpawnPoint = Object::cast_to<Node>( get_node("SpawnPoint") );
	
}

void ServerManager::CreateServer()
{
	Godot::print("Trying to start server...");

	server->connect("client_connected", this, "OnClientConnected");
	server->connect("client_disconnected", this, "OnClientDisconnected");
	server->connect("client_close_request", this, "OnClientCloseRequest");
	server->connect("data_received", this, "OnDataReceived");

	Error listen =  server->listen(Port);

	if (listen != godot::Error::OK) {
		Godot::print("Unable to start server.");
		set_process(false);
	}
	else{ 
		Godot::print("Server started succesfully..."); 
	}

}

void ServerManager::OnClientConnected(int id, godot::String proto)
{
	godot::String _id = godot::String(std::to_string(id).c_str());
	Godot::print("Client connected with id : "+ _id);
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> _player = reLo->load("res://Assets/Player.tscn");
	
	Node* player = _player->instance();
	player->set_name(_id);
	get_node("SpawnPoint")->add_child(player);
	
	SendData::SpesificId(id, DataStringifier::IdInfo(id) );
	SendData::AllPlayers(DataStringifier::NewPlayerJoinedWithId(id));
	
	std::vector<int> PeersArray = ConnectedPeers::GetPeersArray();
	if (PeersArray.size() > 0) {
		for (int i : PeersArray) {
			Node2D* player = get_node<Node2D>(NodePath("SpawnPoint/" + godot::String(std::to_string(i).c_str())) );
			float x = player->get_transform().get_origin().x;
			float y = player->get_transform().get_origin().y;
			SendData::SpesificId(id, DataStringifier::OldPlayerDataToJoinedPlayer(i, x, y));
		}
	}
	ConnectedPeers::InsertPeer(id);
}

void ServerManager::OnClientDisconnected(int id, bool was_clean_close)
{
	godot::String _id = godot::String(std::to_string(id).c_str());
	Godot::print("Client disconnected with id : " + _id);
	NodePath path = NodePath("SpawnPoint/" + _id);
	if (has_node(path)) {
		get_node(path)->queue_free();
		ConnectedPeers::DeletePeer(id);
		SendData::AllPlayers(DataStringifier::ClientDisconnected(id));
	}
	
}

void ServerManager::OnClientCloseRequest(int id, int code, godot::String reason)
{
	godot::String _id = godot::String(std::to_string(id).c_str());
	Godot::print("Client closed with id : " + _id);
	NodePath path = NodePath("SpawnPoint/" + _id);
	if (has_node(path)) {
		get_node(path)->queue_free();
		ConnectedPeers::DeletePeer(id);
		SendData::AllPlayers(DataStringifier::ClientDisconnected(id));
	}
}

void ServerManager::_process(const double p_delta)
{
	server->poll();
}

Variant ServerManager::GetPeer(int id) {
	godot::Array args;
	args.append(id);

	Variant peer = server->callv("get_peer", args);
	return peer;
}

void ServerManager::PutPacket(Variant peer, godot::String data) {
	Variant _data(data);
	Variant utf8_buffer = _data.call("to_utf8", nullptr, 0);
	Variant* buffer[1] = { &utf8_buffer };

	peer.call("put_packet", (const Variant**)buffer, 1);
}

godot::String ServerManager::GetPacket(Variant peer){
	Variant pktBuffer = peer.call("get_packet", nullptr, 0);
	godot::String pkt = pktBuffer.call("get_string_from_utf8", nullptr, 0);
	return pkt;
}

void ServerManager::OnPingTimerTimeout() {
	using namespace std::chrono;
	uint64_t currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	lastSendedPingTime = currentTime;
	Godot::print("lastPingTimeONSERVERMANAGER = " + godot::String(std::to_string(lastSendedPingTime).c_str()));
	SendData::AllPlayers(DataStringifier::Ping());
}

void ServerManager::SetPlayerDisplayName(int id, std::string _displayName) {
	Peer* player = ConnectedPeers::GetPeer(id);
	player->displayName = _displayName;
}



/*
                         _       _       _
      ___  ___ _ __   __| |   __| | __ _| |_ __ _ 
     / __|/ _ \ '_ \ / _` |  / _` |/ _` | __/ _` |
     \__ \  __/ | | | (_| | | (_| | (_| | || (_| |
     |___/\___|_| |_|\__,_|  \__,_|\__,_|\__\__,_|

*/
                                              

void SendData::SpesificIds(std::vector<int> ids, godot::String data)
{
	for (int i : ids) { PutPacket(GetPeer(i), data); }
}

void SendData::AllPlayers(godot::String data)
{
	std::vector<int> PeersArray = ConnectedPeers::GetPeersArray();
	for (int i : PeersArray) { PutPacket(GetPeer(i), data); }
}

void SendData::AllPlayersExceptIds(std::vector<int> ids, godot::String data)
{
	std::vector<int> PeersArray = ConnectedPeers::GetPeersArray();
	for (int i : PeersArray) {
		bool isOnList = false;
		for (int z : ids) { if (i == z) { isOnList = true; break; } }

		if (isOnList = false) { PutPacket(GetPeer(i), data); }
	}
}

void SendData::SpesificId(int id, godot::String data)
{
	PutPacket(GetPeer(id), data);
}

void SendData::AllPlayersExceptId(int id, godot::String data)
{
	std::vector<int> PeersArray = ConnectedPeers::GetPeersArray();
	for (int i : PeersArray) { if (i != id) { PutPacket(GetPeer(i), data); } }
}