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
	server.instance();
	CreateServer();
	//SpawnPoint = get_node("SpawnPoint");
	
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
	//get_node("SpawnPoint")->add_child(player);
	
	godot::String idinfo = DataStringifier::IdInfo(id);
	Godot::print(idinfo);
	
	SendData::SpesificId(id, idinfo);
}

void ServerManager::OnClientDisconnected()
{
}

void ServerManager::OnClientCloseRequest()
{
	
}

void ServerManager::_process(const double p_delta)
{
	server->poll();
}

Variant ServerManager::GetPeer(int id) {
	godot::Array arr;
	arr.append(id);

	Variant peer = server->callv("get_peer", arr);
	return peer;
}

void ServerManager::PutPacket(Variant peer, godot::String data) {
	Variant _data(data);
	Variant utf8_buffer = _data.call("to_utf8", nullptr, 0);
	Variant* buffer[1] = { &utf8_buffer };

	peer.call("put_packet", (const Variant**)buffer, 1);
}

//SEND DATA FUNCTIONS

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