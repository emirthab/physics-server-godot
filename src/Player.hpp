#pragma once

#include <Godot.hpp>

#include <vector>
#include <Vector2.hpp>
#include <KinematicBody2D.hpp>

using namespace godot;

class Player : public KinematicBody2D 
{
	GODOT_CLASS(Player, KinematicBody2D);

	/*int speed = 200;
	int processTime;

	Vector2 velocity = Vector2::ZERO;
	
	bool isPressingRight = false;
	bool isPressingLeft = false;
	bool isPressingDown = false;
	bool isPressingUp = false;

	std::vector<Vector2> LocationDataHistory;*/

	public:
		static void _register_methods();
		void _process(float delta);

		/*static long PING;

		void receiveMovementData(int key, bool value);
		void setPing();
		void locationDataRecognizer(float delta);
		void syncLagCompensation();*/
		
		
};