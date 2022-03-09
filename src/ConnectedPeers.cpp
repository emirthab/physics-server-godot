#include "ConnectedPeers.h"
#include <Godot.hpp>

struct Peer* head = NULL;

void ConnectedPeers::InsertPeer(int _id, string _displayName)
{
	struct Peer* newnode = (struct Peer*)malloc(sizeof(struct Peer));
	newnode->id = _id;
	strcpy(newnode->displayName, _displayName.c_str());
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
	return;
}

std::vector<int> ConnectedPeers::GetAllIds()
{
	std::vector<int> ids;
	struct Peer* ptr;
	ptr = head;
	while (ptr != NULL) {
		ids.push_back(ptr->id);
		ptr = ptr->next;
	}

	return ids;
}
