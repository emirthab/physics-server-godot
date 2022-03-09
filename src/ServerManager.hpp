#include <Godot.hpp>

#include <Node.hpp>
#include <WebSocketServer.hpp>
#include <string>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

#include "ConnectedPeers.hpp"

using namespace godot;

static WebSocketServer* server = WebSocketServer::_new();

class ServerManager : public Node
{	
	GODOT_CLASS(ServerManager, Node);
	
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
			static void SpesificId(int Id, godot::String Data);
			static void AllPlayersExceptId(int Id, godot::Array Data);
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

};