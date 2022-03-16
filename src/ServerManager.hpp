#pragma once

#include <Godot.hpp>

#include <Node.hpp>
#include <WebSocketServer.hpp>
#include <string>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <iostream>
#include <Node2D.hpp> 
#include <Vector2.hpp>
#include <Array.hpp>
#include <Timer.hpp>

#include <chrono>
#include <iostream>

#include <SceneTree.hpp>

#include "ConnectedPeers.hpp"

using namespace godot;

static Ref<WebSocketServer> server;
static int lastSendedPingTime;

class ServerManager : public Node
{	
	GODOT_CLASS(ServerManager, Node);

	int Port = 3636;
	//Node* SpawnPoint;
	int xSpawn;
	int ySpawn;

	public:
	
	
		static void _register_methods();
	

		void _init();
		void _process(const double p_delta);
		void _ready();

		void CreateServer();

		void OnClientConnected(int id, godot::String proto);
		void OnClientDisconnected(int id, bool was_clean_close);
		void OnClientCloseRequest(int id, int code, godot::String reason);
		void OnDataReceived(const int id);

		void OnPingTimerTimeout();

		static Variant GetPeer(int id);
		static void PutPacket(Variant peer, godot::String data);
		static godot::String GetPacket(Variant peer);
		static godot::Array str2array(godot::String data);
		
		Timer* pingTimer;

		void SetPlayerDisplayName(int id, std::string _displayName);

		
};

class SendData : public ServerManager {
	public:
		static void SpesificIds(std::vector<int> ids, godot::String data);
		static void AllPlayers(godot::String data);
		static void AllPlayersExceptIds(std::vector<int> ids, godot::String data);
		static void SpesificId(int Id, godot::String Data);
		static void AllPlayersExceptId(int id, godot::String data);

};