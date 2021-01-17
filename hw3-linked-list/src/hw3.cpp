#include "hw3.h"

#include <iostream>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

void insertHead(Node*& head, Node*& entry){
	entry->setLink(head);
	head = entry;
}
void insertTail(Node*& head, Node*& entry){
	Node* current = head;
	if(head!=NULL){ //link isn't empty
		while(current->getLink()!=NULL){
			current = current->getLink();
		}
		entry->setLink(NULL);
		current->setLink(entry);
	} else if (head==NULL) {
		insertHead(head,entry);
		return;
	}
}
void insertInd(Node*& head, Node*& entry, size_t pos){
	//pos can be 0
	if(head == NULL){
		insertHead(head,entry);
		return;
	}

	size_t i = 0; //first position of list...
	Node* cursor = head;
	if(head != NULL){
		while(cursor!=NULL && i != (pos-1)){
			//while cursor can still go up a list
			//and while index hasn't hit position yet...
			cursor = cursor->getLink();
			i++;
		}
		if(i==(pos-1)){
			insert(cursor,entry);
		}
	}
}

void insert(Node* prev, Node* entry){
	entry->setLink(prev->getLink());
	prev->setLink(entry);
}

///////////////////////////////////////////////////

void insertHead(Node*& head, const Node::nodeDatatype& entry){
	Node* newHead = new Node(entry, head);
	head = newHead;
}

void insertTail(Node*& head, const Node::nodeDatatype& entry){
	Node* newTail = new Node(entry, head);
	if(head!=NULL){
		Node* cursor = head;
		while(cursor->getLink()!=NULL){
			cursor = cursor->getLink();
		}
			newTail->setLink(NULL);
			cursor->setLink(newTail);
	} else if (head==NULL) {
		insertHead(head,entry);
		return;
	}
}

void insertInd(Node*& head, const Node::nodeDatatype& entry, size_t pos){
	if(pos<0 || pos>length(head)){
		return;
	}
	//Node* newInd = new Node(entry);
	if(head==NULL || pos == 0){
		insertHead(head,entry);
		return;
	} else if (head!=NULL){
		size_t i = 0;
		Node* cursor = head;
		while((cursor != NULL) && (i != (pos-1))){
			cursor = cursor->getLink();
			i++;
		}
		if(i==(pos-1)){
			insert(cursor, entry);
		}
	}
}

void insert(Node* prev, const Node::nodeDatatype& entry){
	Node* insert = new Node(entry);
	insert->setLink(prev->getLink());
	prev->setLink(insert);
}

//////////////////////////////////////////////////////////////

bool isCycle(Node* head){
	Node* p1; //moves up once
	Node* p2; //moves up twice

	if(head=NULL) { return false; }

	for(p1 = head; p1!=NULL; p1=p1->getLink()){
		for(p2=head->getLink(); p2!=NULL && p2->getLink()!=NULL; p2=p2->getLink()->getLink()){
			if(p1 == p2){
				return true;
			}
			//we don't want them to start at the same point
			//otherwise they are equal to eachother from
			//the very beginning.
		}
	}
	return false;
}

bool isEmpty(Node* head){
	//Node* current;
	//current = head->getLink();
	//if head node is empty and the node proceeding the head is
	//empty, then the linked list is empty
	if(head = NULL /*&& current = NULL*/){
		return true;
	} else {
		return false;
	}
}

bool isValid(Node* head, size_t pos){
	size_t i = 0;
	Node* current = head;

	if(head==NULL){
		return false;
		//if list isn't empty
	}
	if(head->getLink()==NULL && pos==0){
		return true;
	}

	while(current!=NULL && i<pos){
		current=current->getLink();
		i++;
		//iterate through list b4 the position
	}
	if(i==pos){ return true; }
	//if index reached the position, then the position exists
	if(i!=pos){ return false; }

	return true;
	//if index didn't reach position, position doesn't exist
}

///////////////////////////////////////////////////

size_t length(const Node* head){
	size_t answer = 0;
	const Node* cursor;

	for(cursor = head; cursor != NULL; cursor = cursor->getLink()){
		++answer;
	}
	return answer;
}
//if we're just locating
//don't worry about the position before node
Node* listLocate(Node* head, size_t position){
	Node* cursor = head;
	size_t i = 0;

	while(cursor!=NULL && i<position){
		cursor=cursor->getLink();
		i++;
	}
	if(i==position){
		return cursor;
	}
	return NULL;
}
const Node* listLocate(const Node* head, size_t pos){
	const Node* cursor = head;
	size_t i = 0;

	while(cursor!=NULL && i<pos){
		cursor=cursor->getLink();
		i++;
	}
	if(i==pos){
		return cursor;
	}
	return NULL;
}

Node* listSearch (Node* head, const Node::nodeDatatype& target){
	Node *cursor = head;
	while(cursor!=NULL){
		if(cursor->getData() == target){
			return cursor;
		}
		cursor=cursor->getLink();
	}
	return NULL;
}

const Node* listSearch(const Node* head, const Node::nodeDatatype& target){
	const Node* cursor;
	for(cursor=head; cursor!=NULL; cursor = cursor->getLink()){
		if(target == cursor->getData()){
			return cursor; //return the address of node
		}
	}
	return NULL;
}

////////////////////////////////////////////

void removeHead (Node*& head){
	Node* deleteMe;
	deleteMe = head;
	head = deleteMe->getLink();
	delete [] deleteMe;
}

void removeAll (Node*& head){
	while(head!=NULL){
		removeHead(head);
	}
}

void removeTail(Node*& head){
	Node* current = head;
	Node* previous = NULL;

	if(head == NULL){
		return;
	}
	if(head->getLink() == NULL){
		removeHead(head);
	}
	while(current->getLink()!=NULL){
		previous = current;
		current = current->getLink();
	}
	//take the delete functions outside of the loop.
	previous->setLink(NULL);
	delete [] current;
}

void removeInd(Node*& head, size_t pos){
	Node* current = head;
	Node* previous = NULL;

	if(head == NULL){
		return;
	} else if(head->getLink() == NULL || pos == 0){
		removeHead(head);
	}

	size_t i = 0;

	while(current->getLink()!=NULL && i<pos-1){
		//to remove at exact position
		previous = current;
		current = current->getLink();
		i++;
	}
	previous->setLink(current->getLink());
	delete [] current;
}

void removeFromTo(Node*& head, size_t from, size_t to){
	if(head==NULL){
		return;
	} else if (head->getLink()==NULL || ((to == 0) && (from == 0))){
		removeHead(head);
	} else if(to > length(head) || from > length(head)){
		return;
	} else if (from > to){
		int swap = from;
		from = to;
		to = swap;
	} else if (from == to){
		removeInd(head, to);
	} else if (from == 0 && to == length(head)-1){
		removeAll(head);
	}

	int difference = to-from+1;

	for(size_t j = 0; j<difference; j++){
		removeInd(head, from);
	}
}

void removeHeadTo(Node*& head, size_t to){
	if(head == NULL){
		return;
	} else if (head->getLink()==NULL || (to == 0)){
		removeHead(head);
	} else if (to > length(head)){
		return;
	} else if (to == length(head)){
		removeAll(head);
	} else if (to > length(head)){

	//position of the head is 0
	//no difference should be needed...

		for(size_t j=0; j<to+1; j++){
			removeHead(head);
		}
	}
}

void removeToTail(Node*& head, size_t from){
	if(head == NULL){
		return;
	} else if (head->getLink()==NULL){
		removeHead(head);
	} else if (from > length(head)){
		return;
	} else if (from == length(head)-1){
		removeTail(head);
	} else if (from == 0){
		removeAll(head);
	}

	for(size_t j=length(head); j>from; j--){
		removeTail(head);
	}
}

////////////////////////////////////////////////

void reverse(Node*& head){

	if (head == NULL){
		return;
	}

	Node* previous = NULL;
	Node* current = head;
	Node* next = NULL;

	while(current!=NULL){
		next = current->getLink();
		current->setLink(previous);
		previous = current;
		current = next;
	}

	head = previous;
}

void print(Node* head){
	Node* cursor;
	cursor = head;
	while(cursor != NULL){
		cout << cursor->getData() << "->";
		cursor = cursor->getLink();
		//even at the head, cursor should print out the data at the node it's pointing to
	}
}

////////////////////////////////////////////////

void swap(Node*& head, size_t pos){

}

void swap(Node*& Head, size_t posI, size_t posJ);