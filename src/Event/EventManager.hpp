#pragma once

#include <Godot.hpp>
#include <Node.hpp>

using namespace godot;

class EventManager : public Node{
    GODOT_CLASS(EventManager, Node);

    public:
		static void _register_methods();
        void _init();
};