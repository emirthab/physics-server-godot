#include "DataStringifier.hpp"

godot::String DataStringifier::IdInfo(int id)
{
	Headers header; std::string data;
	data.append("[" + std::to_string(header.OldPlayerDataToJoinedPlayer) + ",");
	data.append(std::to_string(id) + "]");
	return godot::String(data.c_str());
}

godot::String DataStringifier::NewPlayerJoinedWithId(int id)
{
	Headers header; std::string data;
	data.append("[" + std::to_string(header.OldPlayerDataToJoinedPlayer) + ",");
	data.append(std::to_string(id) + "]");
	return godot::String(data.c_str());
}

godot::String DataStringifier::OldPlayerDataToJoinedPlayer(int id, float PosX, float PosY)
{
	Headers header; std::string data;
	data.append("[" + std::to_string(header.OldPlayerDataToJoinedPlayer) + "," );
	data.append(std::to_string(id) + ",");
	data.append(std::to_string(PosX) + ",");
	data.append(std::to_string(PosY) + "]");
	return godot::String( data.c_str() );
}
