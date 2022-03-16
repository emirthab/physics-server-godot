#include "ConnectedPeers.hpp"

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

struct Peer* ConnectedPeers::GetPeer(int _id)
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

std::vector<int> ConnectedPeers::GetPeersArray()
{
	std::vector<int> arr;
	struct Peer* ptr;
	ptr = head;
	while (ptr != NULL) {
		arr.push_back(ptr->id);
		ptr = ptr->next;
	}
	return arr;
}

void ConnectedPeers::DeletePeer(int _id)
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
			ptr = ptr->next;
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

	return;
}
