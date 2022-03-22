#include <Godot.hpp>
#include "ServerManager.hpp"
#include "Entity/Player.hpp"
#include "Event/EventManager.hpp"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
	godot::Godot::nativescript_init(handle);

	godot::register_class<ServerManager>();
	godot::register_class<EventManager>();
	
	godot::register_class<Player>();
}
