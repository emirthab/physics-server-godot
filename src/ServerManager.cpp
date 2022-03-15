#include "ServerManager.hpp"
#include "DataStringifier.hpp"

using namespace godot;

void ServerManager::_register_methods()
{
	register_method("_init", &ServerManager::_init);
	register_method("_process", &ServerManager::_process);

	register_method("OnDataReceived", &ServerManager::OnDataReceived);
	
	register_method("OnClientConnected", &ServerManager::OnClientConnected);
	register_method("OnClientDisconnected", &ServerManager::OnClientDisconnected);
	register_method("OnClientCloseRequest", &ServerManager::OnClientCloseRequest);

}

void ServerManager::_init()
{
	pingTimer->set_wait_time(0.5);
	pingTimer->set_one_shot(false);
	pingTimer->connect("timeout", this, "OnPingTimerTimeout");
	add_child(pingTimer);
	pingTimer->start();

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

	if (PeersArray.size() > 0) {
		for (int i : PeersArray) {
			Node2D* player = get_node<Node2D>(NodePath("SpawnPoint/" + godot::String(std::to_string(i).c_str())) );
			float x = player->get_transform().get_origin().x;
			float y = player->get_transform().get_origin().x;
			SendData::SpesificId(id, DataStringifier::OldPlayerDataToJoinedPlayer(i, x, y));
		}
	}
	ConnectedPeers::InsertPeer(id);
	PeersArray.push_back(id);
}

void ServerManager::OnClientDisconnected(int id, bool was_clean_close)
{
	godot::String _id = godot::String(std::to_string(id).c_str());
	Godot::print("Client disconnected with id : " + _id);
	ConnectedPeers::DeletePeer(id);
	NodePath path = NodePath("SpawnPoint/" + _id);
	if (has_node(path)) {
		get_node(path)->queue_free();
	}
	
}

void ServerManager::OnClientCloseRequest(int id, int code, godot::String reason)
{
	godot::String _id = godot::String(std::to_string(id).c_str());
	Godot::print("Client closed with id : " + _id);
	ConnectedPeers::DeletePeer(id);
	NodePath path = NodePath("SpawnPoint/" + _id);
	if (has_node(path)) {
		get_node(path)->queue_free();
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
	//Godot::print(pkt);
	return pkt;
}

void ServerManager::OnPingTimerTimeout() {
	auto now = std::chrono::system_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
	//lastSendedPingTime = value.count();
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
	for (int i : ids) { PutPacket(i, data); }
}

void SendData::AllPlayers(godot::String data)
{
	for (int i : PeersArray) { PutPacket(i, data); }
}

void SendData::AllPlayersExceptIds(std::vector<int> ids, godot::String data)
{
	for (int i : PeersArray) {
		bool isOnList = false;
		for (int z : ids) { if (i == z) { isOnList = true; break; } }

		if (isOnList = false) { PutPacket(i, data); }
	}
}

void SendData::SpesificId(int id, godot::String data)
{
	PutPacket(GetPeer(id), data);
}

void SendData::AllPlayersExceptId(int id, godot::String data)
{
	for (int i : PeersArray) { if (i != id) { PutPacket(GetPeer(id), data); } }
}