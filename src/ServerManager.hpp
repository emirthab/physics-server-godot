#pragma once

#include <Godot.hpp>

#include <Node.hpp>
#include <WebSocketServer.hpp>
#include <string>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <PacketPeer.hpp>
#include <iostream>

#include "ConnectedPeers.hpp"

using namespace godot;

class ServerManager : public Node
{	
	GODOT_CLASS(ServerManager, Node);

	int Port = 3636;

	Node* SpawnPoint;
	int xSpawn;
	int ySpawn;

	class SendData
	{
		public:
			void SpesificIds(std::vector<int> ids, godot::Array data);
			void AllPlayers(godot::Array data);
			void AllPlayersExceptIds(std::vector<int> ids, godot::Array data);
			void SpesificId(int Id, godot::String Data);
			void AllPlayersExceptId(int id, godot::Array data);
	};


public:

	WebSocketServer* server = WebSocketServer::_new();

	static void _register_methods();
	
	void _init();
	void _process(const double p_delta);

	void CreateServer();

	void OnClientConnected(int id, godot::String proto);
	void OnClientDisconnected();
	void OnClientCloseRequest();
	void OnDataReceived(const int id);


};