#ifndef __HW4Q1_CPP__
#define __HW4Q1_CPP__
#include "hw4q1.h"

#include <algorithm>

template<class Item>
Stack<Item>::Stack(const Stack& source){
	capacity = source.capacity;
	Item* newData = new Item[capacity];
	used = source.used;

	copy(source.data, source.data + source.used, newData);
	data = newData;
}

template<class Item>
Stack<Item>::~Stack(){
	delete [] data;
}

template<class Item>
void Stack<Item>::push(const Item& entry){
	assert(used<capacity);
	data[used] = entry; //entry pushes itself to the rear of the stack
	used++; //amout of elements goes up
}

template <class Item>
void Stack<Item>::pop(){
	assert(!empty());
	--used; //when u pop out, there is one less item
}

template <class Item>
Item Stack<Item>::top() const{
	assert(!empty());
	return data[used-1];
	//if used has 8 items
	//we disregard the 8th one for the 7th
	//because an array starts at 0
}

template <class Item>
void Stack<Item>::operator=(const Stack<Item>& source){
	if (this == &source){
		return;
	} //forgot to put this into priority queue, whoopsie....
	//test it on ur own i'm tired.

	capacity = source.capacity;
	Item* newData = new Item[capacity];
	used = source.used;
	copy(source.data, source.data + source.used, newData);
	data = newData;
}
#endif