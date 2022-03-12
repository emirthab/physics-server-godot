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
	ConnectedPeers::InsertPeer(1, "deneme");d
	ConnectedPeers::InsertPeer(2, "deneme2");
	std::vector<int> array = ConnectedPeers::GetAllIds();
	for (int i = 0; i < array.size(); i++) {
		Godot::print(String(std::to_string(array[i]).c_str()));
	}
	*/
	Godot::print("This is a init");
	CreateServer();
	SpawnPoint = get_node("SpawnPoint");
	
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

	godot::Array arr;
	arr.append(id);
	Variant peer = server->callv("get_peer", arr);
	Godot::print(peer);

	Variant _data("Demo Buffer");
	Variant utf8_buffer = _data.call("to_utf8", nullptr, 0);
	Variant* buffer[] = { &utf8_buffer };

	peer.call("put_packet", (const Variant**)buffer, 1);
	//SendData::SpesificId(12, "sad");;
	//peer.call("put_packet", (const Variant **)"sad", 1);
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