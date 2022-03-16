#include "Player.hpp"
#include "ServerManager.hpp"
#include "DataStringifier.hpp"

using namespace godot;

void Player::_register_methods()
{
	register_method("_physics_process", &Player::_physics_process);
	register_method("_init", &Player::_init);
	register_method("receiveMovementData", &Player::receiveMovementData);
	register_method("setPing", &Player::setPing);
}

void Player::_init()
{
	Godot::print("Player Created!");
}

void Player::receiveMovementData(int key, bool value)
{
	SendData sendData;

	switch (key)
	{
	case 0: 
		isPressingRight = value;
		break;
	case 1: 
		isPressingLeft = value;
		break;
	case 2: 
		isPressingDown = value;
		break;
	case 3: 
		isPressingUp = value;
		break;
	}
	sendData.AllPlayersExceptId(get_name().to_int(), DataStringifier::MovementInputData(get_name().to_int(), key, value));
	syncLagCompensation();
}

void Player::setPing()
{
	PING = lastSendedPingTime - time(nullptr) * 1000;
	Godot::print(std::to_string(PING).c_str());

}

void Player::locationDataRecognizer(float delta)
{
	if (!processTime) { processTime = int(1.0 / delta); }

	if (LocationDataHistory.size() > 0 && LocationDataHistory.size() == processTime) {
			LocationDataHistory.erase(LocationDataHistory.begin() + 0);
	}
	LocationDataHistory.push_back(get_transform().get_origin());
}

void Player::syncLagCompensation()
{
	float distanceIndex = (1000 - PING / 2) * processTime / 1000;
	int backIndex = round(processTime - distanceIndex);
	int arrayIndex = LocationDataHistory.size() - backIndex;

	Vector2 pos;
	if (LocationDataHistory.size() >= arrayIndex) {
		pos = LocationDataHistory[arrayIndex];
		get_transform().set_origin(pos);
		SendData sendData;
		sendData.AllPlayers(DataStringifier::LagCompensationPosition(get_name().to_int(), pos.x, pos.y));
	}

}

void Player::_physics_process(float delta)
{
	locationDataRecognizer(delta);
	velocity = Vector2(0,0);
	if (isPressingRight == 1) { velocity.x += 1; };
	if (isPressingLeft == 1) { velocity.x -= 1; };
	if (isPressingDown == 1) { velocity.y += 1; };
	if (isPressingUp == 1) { velocity.y -= 1; };

	//Godot::print(velocity);
	velocity = velocity.normalized() * speed;
	velocity = move_and_slide(velocity);
	
}
