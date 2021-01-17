#ifndef __GRAPHM_CPP_
#define __GRAPHM_CPP_

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <algorithm>

#include "hw6q1.h"

using namespace std;

// CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(){
	capacity = DEF_CAP;
	count = 0;
	label = new Item[capacity]; //vertices
	for(int j = 0; j < capacity; j++){
		matrix[j] = new int*[capacity]; //columns of matrix
	}
	//matrix = new int*[capacity]; //columns of matrix
	for(int i = 0; i < capacity; i++){
		matrix[i] = new int[capacity]; //rows
	}
	//matrix[capacity][capacity]; basically rows, then columns
}

template <class Item>
graphM<Item>::graphM(const graphM<Item>& source){
	capacity = source.capacity;
	count = source.count;
	int i;
	//copy(source.label[0], source.label[0] + source.label[capacity-1], label);
	//copy(source.matrix[0][0], source.matrix[0][0] + source.matrix[capacity-1][capacity-1], matrix);

	label = new Item[capacity];
	for(i = 0; i < count; i++){
		label[i] = source.label[i];
	}

	matrix = new Item*[capacity]; //consider that we have a bunch of columns
	for(i = 0; i < capacity; i++){
		for(int j = 0; j < capacity; j++){
			matrix[i][j] = source.matrix[i][j];
		}
	}
}

// MODIFICATION MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::addVertex(const Item& inLabel){
	if(count < capacity){
		label[count] = inLabel;
		count++;
	}
}

template <class Item>
void graphM<Item>::addEdge(size_t source, size_t target, int weight){
	assert(source < count && target < count && weight > 0);
	matrix[source][target] = weight; //v1 to v2
	//matrix[target][source] = weight; too, if undirected graph
}

template <class Item>
void graphM<Item>::removeEdge(size_t source, size_t target){
	assert(source < count && target < count);
	matrix[source][target] = 0;
}

// CONSTANT MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::print() const{
	//use number of vertices to show the max amount of rows and columns there can be
	//if there are 6 vertices (0...6), then it's a 6 by 6 matrix
	if(count > 0){
		for(int i = 0; i < numVertices; i++){ //for the row
			for(int j = 0; j < numVertices; j++){ //for the column
				cout << matrix[i][j] << " ";
			}
			cout << endl; //go to next row
		}
	}
	//basically, fill out each row with a number per column, either 0 or 1
}

template <class Item>
size_t graphM<Item>::numVertices() const{
	return count;
}

template <class Item>
size_t graphM<Item>::numEdges() const{
	//edges are found in matrices
	//assume matrix[row][col]

	size_t row = sizeof(matrix)/sizeof(matrix[0]); //size of row
	size_t col = sizeof(matrix[0])/sizeof(int); //size of column
	size_t numEd = row * col;

	return numEd;
}

template <class Item>
bool graphM<Item>::isEdge(size_t source, size_t target) const{
	if(matrix[source][target] > 0)
		return true;
	else
		return false;
}

template <class Item>
Item* graphM<Item>::neighbors(size_t vertex) const{
	assert(count > 0);

	int v = 0;
	Item* neighbourhood = new Item[count]; //can't have more than exists already

	for(int k = 0; k < count; k++){
		if(label[k] == vertex){ //if vertex is valid
			for(int i = 0; i < count; i++){ //go up the number of vertices in the row
				for(int j = 0; j < count; j++){ //go up number of vertices in the column
					if(matrix[vertex][j] > 0){
						neighbourhood[v] = label[j]; //insert the weight of the edge w/ vertex at j into the neighborhood
						v++;						 //go to the next available space in neighborhood
					}
				} 									 
			}
			return neighbourhood;
		} //else, keep going
	}
}

#endif