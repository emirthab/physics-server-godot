#include <iostream>
#include <string>
#include <vector>
#include <Godot.hpp>
using namespace std;

struct Peer {
	int id;
	std::string displayName;
	struct Peer* prev;
	struct Peer* next;
};

class ConnectedPeers {

	public:

		static void InsertPeer(int _id);
		static void DeletePeer(int _id);
		static struct Peer* GetPeer(const int _id);
		static std::vector<int> GetPeersArray();
};