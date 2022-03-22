#include "EventManager.hpp"

void EventManager::_register_methods(){
    register_method("_init", &EventManager::_init);

};

void EventManager::_init(){
    Godot::print("İnitDemo");
}