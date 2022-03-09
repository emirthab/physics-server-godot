#include "Server.hpp"

void Server::_register_methods()
{

	register_method("_init", &Server::_init);
	register_method("_process", &Server::_process);

	register_method("OnDataReceived", &Server::OnDataReceived);
	
	register_method("OnClientConnected", &Server::OnClientConnected);
	register_method("OnClientDisconnected", &Server::OnClientDisconnected);
	register_method("OnClientCloseRequest", &Server::OnClientCloseRequest);

	
}

void Server::_init()
{
	PoolByteArray arr = StringToBuffer("deneme yazý");
	for (int i = 0; i < arr.size(); i++) {
		Godot::print("asd" + String(arr[i]));
	}


	ConnectedPeers::InsertPeer(1, "deneme");
	ConnectedPeers::InsertPeer(2, "deneme2");
	std::vector<int> array = ConnectedPeers::GetAllIds();
	for (int i = 0; i < array.size(); i++) {
		Godot::print(String(std::to_string(array[i]).c_str()));
	}
	CreateServer();
	SpawnPoint = get_node("SpawnPoint");
	
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
	godot::String _id = godot::String(std::to_string(id).c_str());
	Godot::print("Client connected with id : "+ _id);
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> _player = reLo->load("res://Assets/Player.tscn");
	
	Node* player = _player->instance();
	player->set_name(_id);
	get_node("SpawnPoint")->add_child(player);

}

void SendOldPlayersDataToJoinedPlayer() 
{
	
}

void Server::OnClientDisconnected()
{
}

void Server::OnClientCloseRequest()
{
	
}

void Server::SendData::SpesificIds(std::vector<int> ids, godot::Array data)
{
	for (int i = 0; i < ids.size(); i++) {
		//Ref<WebSocketPeer> peer = server->get_peer(1);
		//PoolByteArray _pack = StringToBuffer("bu bir deneme buffferidir.");
		
		//server->put_packet(_pack);
	}
}

void Server::SendData::AllPlayers(godot::Array data)
{
}

void Server::SendData::AllPlayersExceptIds(std::vector<int> ids, godot::Array data)
{
}

void Server::SendData::SpesificId(int id)
{
	//Ref<PacketPeer> peer = server->get_peer(id);
	//PoolByteArray _pack = StringToBuffer("bu bir deneme buffferidir.");

	//peer->put_packet(_pack);
}

void Server::SendData::AllPlayersExceptId(int id, godot::Array data)
{
}


void Server::_process(const double p_delta)
{
	server->poll();
}

PoolByteArray Server::StringToBuffer(char* data)
{
	PoolByteArray arr;
	for (int i = 0; i < strlen(data); i++) {
		Godot::print("arraya atandý");
		arr.set(i, data[i] );
	}

	return arr;
}