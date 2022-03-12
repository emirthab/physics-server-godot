#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Peer {
	int id;
	char displayName[16];
	struct Peer* prev;
	struct Peer* next;
};

class ConnectedPeers {

	public:
	
		static std::vector<int> PeersArray;
		static void InsertPeer(int _id, string _displayName);
		static void DeletePeer(int _id);
		static struct Peer* GetPeer(const int _id);

};