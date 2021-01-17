#ifndef __HW4Q5_CPP__
#define __HW4Q5_CPP__

#include "hw4q5.h"
#include <algorithm>
using namespace std;

//LITERALLY
//the same concept as 2 stacks, one queue
//except ur goal is to take out the newest element to come in
//not the oldest element

//PUSH:
//while the first queue is not empty, push everything to temp q
//then push the entry into the first queue
//then move everything back from the temp queue
//all the elements from temp queue will be behind entry
//one more element in our "stack", hooray!

//POP:
//newest element, which is entry, comes out
//one less item in our "stack", hooray!

template<class Item>
Queue2Stack<Item>::Queue2Stack(){
	used = 0;
}

template<class Item>
void Queue2Stack<Item>::push(const Item& entry){
	while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
	}
	q1.push(entry);
	while(!q2.empty()){
		q1.push(q2.front());
		q2.pop();
	}
	used++;
}

template<class Item>
void Queue2Stack<Item>::pop(){
	assert(!q1.empty());
	q1.pop(); //pops the newest element to come in
	used--;
}

template<class Item>
size_t Queue2Stack<Item>::size() const{
	return used;
}

template<class Item>
bool Queue2Stack<Item>::empty() const{
	return q1.empty();
}

template<class Item>
Item Queue2Stack<Item>::top() const{
	return q1.front();
}

#endif