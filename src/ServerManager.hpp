#pragma once

#include <Godot.hpp>

#include <Node.hpp>
#include <WebSocketServer.hpp>
#include <string>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <PacketPeer.hpp>
#include <iostream>
#include <Ref.hpp>

#include "ConnectedPeers.hpp"

using namespace godot;

static Ref<WebSocketServer> server;

class ServerManager : public Node
{	
	GODOT_CLASS(ServerManager, Node);

	int Port = 3636;

	Node* SpawnPoint;
	int xSpawn;
	int ySpawn;

public:
	
	
	static void _register_methods();
	

	void _init();
	void _process(const double p_delta);

	void CreateServer();

	void OnClientConnected(int id, godot::String proto);
	void OnClientDisconnected();
	void OnClientCloseRequest();
	void OnDataReceived(const int id);

	static Variant GetPeer(int id);
	static void PutPacket(Variant peer, godot::String data);

};

class SendData : public ServerManager {
	public:
		static void SpesificIds(std::vector<int> ids, godot::String data);
		static void AllPlayers(godot::String data);
		static void AllPlayersExceptIds(std::vector<int> ids, godot::String data);
		static void SpesificId(int Id, godot::String Data);
		static void AllPlayersExceptId(int id, godot::String data);

};