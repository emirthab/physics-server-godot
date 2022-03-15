#include "ConnectedPeers.hpp"
#include <Godot.hpp>

struct Peer* head = NULL;

void ConnectedPeers::InsertPeer(int _id)
{
	struct Peer* newnode = (struct Peer*)malloc(sizeof(struct Peer));
	newnode->id = _id;
	newnode->prev = NULL;
	newnode->next = head;
	if (head != NULL)
		head->prev = newnode;
	head = newnode;
}

struct Peer* ConnectedPeers::GetPeer(const int _id)
{
	struct Peer* ptr;
	ptr = head;
	while (ptr != NULL) {
		if (ptr->id == _id) {
			return ptr;
			break;
		}
		else {
			ptr = ptr->next;
		}
	}
	return NULL;
}

void ConnectedPeers::DeletePeer(const int _id)
{
	struct Peer* ptr;
	struct Peer* del = NULL;
	ptr = head;
	while (ptr != NULL) {
		if (ptr->id == _id) {
			del = ptr;
			break;
		}
		else {
			del = del->next;
		}
	}

	if (head == NULL || del == NULL)
		return;

	if (head == del)
		head = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	free(del);
	
	PeersArray.erase(std::remove(PeersArray.begin(), PeersArray.end(), _id), PeersArray.end());

	return;
}
