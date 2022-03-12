#include "ServerManager.hpp"

void ServerManager::SendData::SpesificIds(std::vector<int> ids, godot::Array data)
{
	for (int i = 0; i < ids.size(); i++) {

		/*ServerManager Manager;

		Variant _data(data);
		Variant utf8_buffer = _data.call("to_utf8", nullptr, 0);
		Variant* buffer[] = { &utf8_buffer };

		godot::Array arr;
		arr.append(id);

		Godot::print("send datadaki");
		Variant peer = Manager.server->callv("get_peer", arr);
		Godot::print(peer);
		peer.call("put_packet", (const Variant**)buffer, 1);
		*/
	}
}

void ServerManager::SendData::AllPlayers(godot::Array data)
{
}

void ServerManager::SendData::AllPlayersExceptIds(std::vector<int> ids, godot::Array data)
{
}

void ServerManager::SendData::SpesificId(int id, godot::String data)
{
	ServerManager Manager;

	Variant _data(data);
	Variant utf8_buffer = _data.call("to_utf8", nullptr, 0);
	Variant* buffer[] = { &utf8_buffer };

	godot::Array arr;
	arr.append(id);

	Variant peer = Manager.server->callv("get_peer", arr);
	peer.call("put_packet", (const Variant**)buffer, 1);
}

void ServerManager::SendData::AllPlayersExceptId(int id, godot::Array data)
{
}
