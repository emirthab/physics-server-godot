#pragma once

#include <Godot.hpp>
#include "../Entity/Player.hpp"
#include "../EventManager.hpp"

using namespace godot;
 
class PlayerMovementEvent : public EventManager{
    Player* player;
    
};