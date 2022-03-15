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
		int OldPlayerDataToJoinedPlayer = 0x02;
		int ClientDisconnected = 0x03;
		int Ping = 0x06;
		int MovementInputData = 0x05;

	};

public:

	static godot::String IdInfo(int id);
	static godot::String NewPlayerJoinedWithId(int id);
	static godot::String OldPlayerDataToJoinedPlayer(int id, float PosX, float PosY);
	static godot::String ClientDisconnected(int id);
	static godot::String Ping();
	static godot::String MovementInputData(int id, int key, int value);
};