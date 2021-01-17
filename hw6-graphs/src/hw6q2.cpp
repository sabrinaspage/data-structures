#ifndef __GRAPHL_CPP__
#define __GRAPHL_CPP__

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include "hw6q2.h"

template <class Item>
graphL<Item>::graphL(){
	capacity = DEF_CAP;
	count = 0;

	label = new Item[capacity]; //list of up to 30 vertices
	list = new node<graphData>*[capacity];

	//up to 30 vertices hold up to 30 neighbors, at most
	for(int i = 0; i < capacity; i++){
		list[i] = NULL;
		//meaning the every vertex in list doesn't have any
		//neighbors right now, so it's initialized to NULL
	}
}

template <class Item>
graphL<Item>::graphL(const graphL<Item>& source){
	if(source == NULL){
		return;
	}
    //since source is graphL, change its stuff
	capacity = source.capacity;
	count = source.count;
	label = new Item[capacity];
	list = new node<graphData>*[capacity];

	//list: node of type graphData
	//uses

	for(int i = 0; i < capacity; i++){
		if(source.list[i] != NULL){
			node<graphData>* head = NULL; //create a head and tail
			node<graphData>* tail = NULL;
			node<graphData>* sourcePtr = source.list[i]; //create a pointer to point to start of list
			list_copy(sourcePtr, head, tail);
			list[i] = head;
		} else {
			continue;
		}
	}
}

//No destructor?! Oh whale

// MODIFICATION MEMBER FUNCTIONS

template <class Item>
void graphL<Item>::addVertex(const Item& inLabel){
	assert(count < capacity);
		label[count] = inLabel;
		count++;
}

template <class Item>
void graphL<Item>::addEdge(size_t source, size_t target, int weight){
	assert((source < count) && (target < count) && (weight > 0));

	graphData newGraphData(target, weight); //inserts vertex and weight

	node<graphData>* nNode = new node<graphData>(newGraphData);
	//Node has a vertex and a weight
	if(list[source] == NULL){
		list[source] = nNode;
	} else {
		//node_iterator<Item>* curr = label[source]; //create a current node, point it to label
		//node_iterator<Item>* prev = NULL; //prev will go before current

		node<graphData>* graphCurr = list[source];

		if(graphCurr->data().getV() == target){
			graphCurr->data().setW(weight);
			return;
		}
		while(graphCurr->link() != NULL){
			graphCurr = graphCurr->link();
		}
		graphCurr->set_link(nNode);
	}
}

template <class Item>
void graphL<Item>::removeEdge(size_t source, size_t target){
	if(count > 0 && source < count && target < count){
	    //graphCurrent is a node pointer with graphdata functions
		//node<graphData> *prev = graphCurr; //previous is before graphCurrent
		if(list[source] == NULL) return; //if empty adjacency list, return

		if(list[source]->data().getV() == target){
			list_head_remove(list[source]);
			return;
		} //if the start of the list is == to target, return with head removed

		node<graphData> *find = list[source];
		while(find != NULL){
			if(find->data().getV() == target){
				list_remove(find);
				//no need for previous
				//that's why this function exists in node toolbox
				return;
			}
			find = find->link();
		}
	}
}

// CONSTANT MEMBER FUNCTIONS
template <class Item>
void graphL<Item>::print() const{
	//print adjacency list
	
}

template <class Item>
size_t graphL<Item>::numVertices() const{
	return count;
}

template <class Item>
size_t graphL<Item>::numEdges() const{
	size_t numEdge = 0;
	for(int k = 0; k < count; k++){
		node<graphData>* graphCurr = list[k]; //point to first index of list
		if(graphCurr == NULL){
			if(k != count - 1){
				continue; //go to the following pointer
			}
		} else {
			while(graphCurr != NULL){
				numEdge++;
				graphCurr = graphCurr->link();
			}
		}
	}
	return numEdge;
}

template <class Item>
bool graphL<Item>::isEdge(size_t source, size_t target) const{
	if(count > 0){
		node<graphData> *graphCurr = list[source]; //start at beginning of vertices
		while(graphCurr != NULL){
			if(graphCurr->data().getV() == target){
				return true;
			} else {
				graphCurr = graphCurr->link();
			}
		}
	}
	return false;
	//iterate through list
	//if the data from the vertex == target, then return true
	//else return false
}

template <class Item>
node<Item>* graphL<Item>::neighbors(size_t vertex) const{
	node<Item>* head = NULL; //head of linked list

	if(list[vertex] == NULL){
		return NULL;
	} else {
		node<graphData>* graphCurr = NULL; //points to weight and vertices from list
		graphCurr = list[vertex]; //points to source vertex
		head = new node<Item>(label[graphCurr->data().getV()]); //head's first neighbor is from list[vertex]

		node<Item>* neighborhood = head; //points to first neighbor
		graphCurr = graphCurr->link(); //iterate to next vertex

		while(graphCurr != NULL){
			node<Item>* neighbor = new node<Item>(label[graphCurr->data().getV()]);
			neighborhood->set_link(neighbor); //add neighbor to neighborhood
			neighborhood = neighborhood->link();
			graphCurr = graphCurr->link();
		}
	}
	return head;
}

#endif

/*
|5|->|3|->|2|-> //5 is a neighbor of 3 and 2
|3|->|1|->|5|-> //3 has neighbors 1 and 5
|2|->|1|->|5| //2 has neighbors 1 and 5
|1|->|1|->|2|->|3|-> //1 has neighbors of itself, 2, and 3
*/