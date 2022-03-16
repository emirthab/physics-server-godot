#pragma once

#include <Godot.hpp>

#include <vector>
#include <Vector2.hpp>
#include <KinematicBody2D.hpp>
#include <math.h>

using namespace godot;

class Player : public KinematicBody2D 
{
	GODOT_CLASS(Player, KinematicBody2D);

	int speed = 200;

	Vector2 velocity = Vector2(0,0);
	
	int isPressingRight = 0;
	int isPressingLeft = 0;
	int isPressingDown = 0;
	int isPressingUp = 0;

	int processTime;

	std::vector<Vector2> LocationDataHistory;

	public:
		static void _register_methods();
		void _init();
		void _physics_process(float delta);

		uint64_t PING;

		void receiveMovementData(int key, bool value);
		void setPing();
		void locationDataRecognizer(float delta);
		void syncLagCompensation();
		
		
};