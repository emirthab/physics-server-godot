#include "ServerManager.hpp"

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

	/*
	ConnectedPeers::InsertPeer(1, "deneme");
	ConnectedPeers::InsertPeer(2, "deneme2");
	std::vector<int> array = ConnectedPeers::GetAllIds();
	for (int i = 0; i < array.size(); i++) {
		Godot::print(String(std::to_string(array[i]).c_str()));
	}
	*/

	CreateServer();
	SpawnPoint = get_node("SpawnPoint");
	
}

void ServerManager::CreateServer()
{

	server->connect("client_connected", this, "OnClientConnected");
	server->connect("client_disconnected", this, "OnClientDisconnected");
	server->connect("client_close_request", this, "OnClientCloseRequest");
	server->connect("data_received", this, "OnDataReceived");

	Godot::print("Trying to start server...");
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

	SendData::SpesificId(id, "Bu bir deneme bufferidýr...");
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