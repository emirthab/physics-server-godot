#include "Server.hpp"
#include "ConnectedPeers.h"

#include <KinematicBody2D.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

void Server::_register_methods()
{

	register_method("_init", &Server::_init);
	register_method("_process", &Server::_process);

	register_method("OnClientConnected", &Server::OnClientConnected);
	register_method("OnClientDisconnected", &Server::OnClientDisconnected);
	register_method("OnClientCloseRequest", &Server::OnClientCloseRequest);
	register_method("OnDataReceived", &Server::OnDataReceived);

	
}

void Server::_init()
{
	Godot::print("Hello World!");
	CreateServer();
}

void Server::CreateServer()
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


void Server::OnClientConnected(const int id,const godot::String &proto)
{
	String _id = godot::String(std::to_string(id).c_str());
	Godot::print("Client connected with id : "+ id);
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> player = reLo->load("res://Assets/Player.tscn");
	player->set_name(_id);
	get_node("SpawnPoint")->add_child(player->instance());
}

void Server::OnClientDisconnected()
{
}

void Server::OnClientCloseRequest()
{
}

void Server::OnDataReceived()
{
}


void Server::_process(const double p_delta)
{
	server->poll();
}

