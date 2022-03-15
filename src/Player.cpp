#include "Player.hpp"
#include "ServerManager.hpp"
#include "DataStringifier.hpp"

void Player::_register_methods()
{
	register_method("_process", &Player::_process);
	register_method("receiveMovementData", &Player::receiveMovementData);
	register_method("setPing", &Player::setPing);
}

void Player::receiveMovementData(int key, bool value)
{
	Godot::print(godot::String(std::to_string(key).c_str()));

	SendData sendData;

	switch (key)
	{
		case 0 : isPressingRight = !value;
		case 1: isPressingLeft = !value;
		case 2: isPressingDown = !value;
		case 3: isPressingUp = !value;
	}
	sendData.AllPlayersExceptId(get_name().to_int(), DataStringifier::MovementInputData(get_name().to_int(), key, value));
}

void Player::setPing()
{
	ServerManager Manager;
	auto now = std::chrono::system_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
	long currentTime = value.count();
	Godot::print(String(currentTime));
	//PING = Manager.lastSendedPingTime - currentTime;
}

void Player::locationDataRecognizer(float delta)
{
}

void Player::syncLagCompensation()
{
}

void Player::_process(float delta)
{
	velocity = Vector2::ZERO;
	if (isPressingRight) { velocity.x += 1; }
	if (isPressingLeft) { velocity.x -= 1; }
	if (isPressingDown) { velocity.y += 1; }
	if (isPressingUp) { velocity.y -= 1; }

	if (velocity != Vector2(0, 0)) {
		velocity = velocity.normalized() * speed;
		velocity = move_and_slide(velocity);
	}
}
