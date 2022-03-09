#include <Godot.hpp>

#include <Node.hpp>
#include <WebSocketServer.hpp>
#include <string>
#include <KinematicBody2D.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

#include <iostream>
#include "ConnectedPeers.hpp"

using namespace godot;

class Server : public Node
{	
	WebSocketServer* server = WebSocketServer::_new();
	GODOT_CLASS(Server, Node);

	int Port = 3636;

	Node* SpawnPoint;
	//int xSpawn;
	//int ySpawn;

	class SendData
	{
		public:
			static void SpesificIds(std::vector<int> ids, godot::Array data);
			static void AllPlayers(godot::Array data);
			static void AllPlayersExceptIds(std::vector<int> ids, godot::Array data);
			static void SpesificId(int id);
			static void AllPlayersExceptId(int id, godot::Array data);
	};


public:

	static void _register_methods();
	void _init();
	void _process(const double p_delta);

	void CreateServer();

	void OnClientConnected(const int id,const godot::String &proto);
	void OnClientDisconnected();
	void OnClientCloseRequest();
	void OnDataReceived(const int id);


	static PoolByteArray StringToBuffer(char* data);
};