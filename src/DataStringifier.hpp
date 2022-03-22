#include <iostream>
#include <vector>

#include <String.hpp>
#include <string>

using namespace std;

class DataStringifier {

	class Headers
	{
	public:
		int IdInfo = 0x00;
		int NewPlayerJoinedWithId = 0x01;
		int OldPlayerPosDataToJoinedPlayer = 0x02;
		int ClientDisconnected = 0x03;
		int Ping = 0x06;
		int MovementInputData = 0x05;
		int LagCompensationPosition = 0x04;
		int NewPlayerJoinedWithName = 0x07;
		int OldPlayerNameDataToJoinedPlayer = 0x08;

	};

public:

	static godot::String IdInfo(int id);
	static godot::String NewPlayerJoinedWithId(int id);
	static godot::String OldPlayerPosDataToJoinedPlayer(int id, float PosX, float PosY);
	static godot::String ClientDisconnected(int id);
	static godot::String Ping();
	static godot::String MovementInputData(int id, int key, int value);
	static godot::String LagCompensationPosition(int id, float PosX, float PosY);
	static godot::String NewPlayerJoinedWithName(int id, std::string name);
	static godot::String OldPlayerNameDataToJoinedPlayer(int id, std::string name);

};