#ifndef __HW4Q2_CPP_
#define __HW4Q2_CPP_

#include "hw4q2.h"
#include <algorithm>
using namespace std;

template <class Item>
Queue<Item>::Queue(){
	used = 0;
	first = 0;
	capacity = DEF_CAP;
	data = new Item[DEF_CAP];
	last = capacity-1;
}

template <class Item>
Queue<Item>::~Queue(){
    delete [] data;
}

template <class Item>
Queue<Item>::Queue(const Queue<Item>& source){
	capacity = source.capacity;
	Item* newData = new Item[source.capacity];
	used = source.used;

	last = source.last;
	first = source.first;
	copy(source.data, source.data+source.used, newData);
	data = newData;
}

template <class Item>
void Queue<Item>::push(const Item& entry){
	assert(used<capacity);
	last = nextIndex(last);
	data[last] = entry;
	used++;
}

template <class Item>
void Queue<Item>::pop(){
	assert(!empty());
	first = nextIndex(first); //first is now the one behind it
	used--; //and now there is one less element
}

template <class Item>
Item Queue<Item>::front() const{
	if(used!=0){
		return data[first]; 
	} return Item();
	//data[0] or wherever is the new front
	//if nothing has been popped then yea
	//first can be 1 or 2 as long as nothing is in front of it
}

template <class Item>
bool Queue<Item>::empty() const{
	return (used == 0);
}

template <class Item>
size_t Queue<Item>::size() const {
	return used;
}

template <class Item>
void Queue<Item>::operator=(const Queue<Item>& source){
	if(this == &source){
		return;
	}
	//if they are all already equal, do nothing

	last = source.last;
	first = source.first;
	capacity = source.capacity;
	used = source.used;

	Item* newData = new Item[source.capacity];
	copy(source.data, source.data+source.used, newData);
	data = newData;
}

#endif