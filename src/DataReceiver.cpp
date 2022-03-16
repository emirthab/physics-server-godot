#include "ServerManager.hpp"

void ServerManager::OnDataReceived(const int id) {
	godot::String _id = godot::String(std::to_string(id).c_str());
	godot::Array args;
	SceneTree* tree = get_tree();

	godot::String pkt = GetPacket(GetPeer(id));
	godot::Array pktArray = str2array(pkt);
	
	switch (int( pktArray[0] ))
	{
		case 0x05 :
			args.append(pktArray[1]);
			args.append(pktArray[2]);
			tree->get_current_scene()->get_node(NodePath("SpawnPoint/" + _id))->callv("receiveMovementData", args);
			break;

		case 0x06 : 
			tree->get_current_scene()->get_node(NodePath("SpawnPoint/" + _id))->callv("setPing", args);
			break;

		//case 0x07 : 

	}
}


godot::Array ServerManager::str2array(godot::String data) {
	data = data.replace("[","");
	data = data.replace("]", "");
	data = data.replace(" ", "");
	godot::PoolStringArray poolArr = data.split(",");
	godot::Array arr;
	for (int i = 0; i < poolArr.size(); i++) {
		godot::String object = poolArr[i];
		if (object.ends_with('"') && object.begins_with('"')) {
			object = object.replace('"', "");
			arr.append(object);
		} else {
			int integerObject = object.to_int();
			arr.append(integerObject);
		}
	}
	return arr;
}
