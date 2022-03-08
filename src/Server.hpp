#include <Godot.hpp>

#include <Node.hpp>
#include <WebSocketServer.hpp>

using namespace godot;

class Server : public Node
{
	GODOT_CLASS(Server, Node);

	int Port = 3636;
	WebSocketServer* server = WebSocketServer::_new();

public:

	static void _register_methods();
	void _init();
	void _process(const double p_delta);

	void CreateServer();

	void OnClientConnected(const int id,const godot::String &proto);
	void OnClientDisconnected();
	void OnClientCloseRequest();
	void OnDataReceived();

};