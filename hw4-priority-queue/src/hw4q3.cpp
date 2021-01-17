#ifndef __HW4_Q3_CPP__
#define __HW4_Q3_CPP__
#include "hw4q3.h"
#include <algorithm>

	//Basically
	//Works like FIFO
	//The element of the most priority must be at the front
	//of the list
	//so basically if u have

	// 5->4->3->, then u pop it, 3, should come out
	//however, if u push 2-> to the front
	//u will have 2->5->4->3->. no good, no good at all!
	//so SWAP 2 and 3, so when we pop it, 2 comes out
	//3->5->4->2->

	//however, lets say we pop again, and the priority is 3 because it's smallest
	//swap 3 and 4, and then 3 comes out, and then switch again

	//this works because push() will never push items out of order

    template <class Item>
    PriorityQueue<Item>::PriorityQueue(){
    	capacity = DEF_CAP;
    	data = new Item[capacity];
    	first = 0;
    	last = capacity-1;
    	used = 0;
    }

    template <class Item>
    PriorityQueue<Item>::PriorityQueue(const PriorityQueue<Item>& source){

    	used = source.used;
    	capacity = source.capacity;
    	last = source.last;
    	first = source.first;
    	Item* newData = new Item[source.capacity];
    	copy(source.data, source.data + source.used, newData);

    	data = newData;
    }

    template <class Item>
    PriorityQueue<Item>::~PriorityQueue(){
    	delete [] data;
    }

    template <class Item>
    void PriorityQueue<Item>::push(const Item& entry){
    	assert(used<capacity);

    	last = nextIndex(last);
    	data[last] = entry;
    	used++;

    	if(data[last] < data[first]){
    		swap(data[last], data[first]);
    	}
    }

    template <class Item>
    void PriorityQueue<Item>::pop(){
    	assert(!empty());
    	if(data[last] < data[nextIndex(first)]){ //if whatever is at used, like 7, is less than whatever is before the front node, 9, then swap 7 and 9
    		swap (data[last], data[nextIndex(first)]);
    	}   

    	first = nextIndex(first);
    	used--;
	}

	template <class Item>
    void swap(Item i, Item j){
    	Item temp = i;
    	i = j;
    	j = temp;
    }

    template <class Item>
    void PriorityQueue<Item>::operator=(const PriorityQueue<Item>& source){
    	data = new Item[source.capacity];
    	capacity = source.capacity;
    	last = source.last;
    	first = source.first;
    	used = source.used;

    	Item* newData = new Item[source.capacity];
    	copy(source.data, source.data + source.used, newData);
    	/*for (int i = 0; i < source.used; i++){
    		newData[i] = source.data[i];
    	}*/
    	data = newData;
    }

    template <class Item>
    size_t PriorityQueue<Item>::size() const{
    	return used;
    }

    template <class Item>
    bool PriorityQueue<Item>::empty() const{
    	return (used == 0);
    }

    template <class Item>
    Item PriorityQueue<Item>::front() const{
    	if(!empty()){
    		return data[first]; //first element in
    	} return Item();
    }

#endif
