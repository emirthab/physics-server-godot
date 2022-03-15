#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Peer {
	int id;
	std::string displayName;
	struct Peer* prev;
	struct Peer* next;
};
static std::vector<int> PeersArray;

class ConnectedPeers {

	public:
	
		static void InsertPeer(int _id);
		static void DeletePeer(int _id);
		static struct Peer* GetPeer(const int _id);

};