#include "ServerManager.hpp"

void ServerManager::SendData::SpesificIds(std::vector<int> ids, godot::Array data)
{
	for (int i = 0; i < ids.size(); i++) {
		//Ref<WebSocketPeer> peer = server->get_peer(1);
		//PoolByteArray _pack = StringToBuffer("bu bir deneme buffferidir.");

		//server->put_packet(_pack);
	}
}

void ServerManager::SendData::AllPlayers(godot::Array data)
{
}

void ServerManager::SendData::AllPlayersExceptIds(std::vector<int> ids, godot::Array data)
{
}

void ServerManager::SendData::SpesificId(int Id, godot::String Data)
{
	Variant _server(server);

	Variant id(Id);
	Variant data(Data);
	Variant utf8_buffer= data.call("to_utf8", nullptr, 0);
	Variant* buffer[] = {&utf8_buffer};

	Variant* args[] = { &id };
	Variant peer = _server.call("get_peer", (const Variant**)args, 1);

	peer.call("put_packet", (const Variant**)buffer, 1);

}

void ServerManager::SendData::AllPlayersExceptId(int id, godot::Array data)
{
}

PoolByteArray StringToBuffer(char* data)
{
	PoolByteArray arr;
	for (int i = 0; i < strlen(data); i++) {
		Godot::print("arraya atandý");
		arr.set(i, data[i]);
	}
	
	return arr;
}