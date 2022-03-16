#include "DataStringifier.hpp"

godot::String DataStringifier::IdInfo(int id)
{
	Headers header; 
	std::string data;
	data.append("[" + std::to_string(header.IdInfo) + ", ");
	data.append(std::to_string(id) + "]");
	return godot::String(data.c_str());
}

godot::String DataStringifier::NewPlayerJoinedWithId(int id)
{
	Headers header; 
	std::string data;
	data.append("[" + std::to_string(header.NewPlayerJoinedWithId) + ", ");
	data.append(std::to_string(id) + "]");
	return godot::String(data.c_str());
}
        
godot::String DataStringifier::OldPlayerDataToJoinedPlayer(int id, float PosX, float PosY)
{
	Headers header; 
	std::string data;
	data.append("[" + std::to_string(header.OldPlayerDataToJoinedPlayer) + ", " );
	data.append(std::to_string(id) + ", ");
	data.append(std::to_string(PosX) + ", ");
	data.append(std::to_string(PosY) + "]");
	return godot::String( data.c_str() );
}

godot::String DataStringifier::ClientDisconnected(int id) {
	Headers header; 
	std::string data;
	data.append("[" + std::to_string(header.ClientDisconnected) + ", ");
	data.append(std::to_string(id) + "]");
	return godot::String(data.c_str());
}

godot::String DataStringifier::Ping() {
	Headers header;
	std::string data;
	data.append("[" + std::to_string(header.Ping) + "]");
	return godot::String(data.c_str());
}

godot::String DataStringifier::MovementInputData(int id, int key, int value)
{
	Headers header;
	std::string data;
	data.append("[" + std::to_string(header.MovementInputData) + ", ");
	data.append(std::to_string(id) + ", ");
	data.append(std::to_string(key) + ", ");
	data.append(std::to_string(value) + "]");
	return godot::String(data.c_str());
}

godot::String DataStringifier::LagCompensationPosition(int id, float PosX, float PosY) {
	Headers header;
	std::string data;
	data.append("[" + std::to_string(header.LagCompensationPosition) + ", ");
	data.append(std::to_string(id) + ", ");
	data.append(std::to_string(PosX) + ", ");
	data.append(std::to_string(PosY) + "]");
	return godot::String(data.c_str());
}