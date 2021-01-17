#ifndef __HW4Q4_CPP__
#define __HW4Q4_CPP__
#include "hw4q4.h"
#include "hw4q1.h"

//BASICALLY
//you have two stacks
//one stack deals with the queue function itself
//the second stack is temporary

//TO PUSH:
//so empty everything in the first stack after pushing
//each element into the temporary stack
//then push your new entry into the empty first stack
//this is in order to keep the element at the bottom, or
//rear of the stack, like in a queue
//and then push back everything in the temp stack
//into the first stack

//TO POP:
//just subtract the amount of elements by one
//and pop the top element of the stack
//recall that the top element is the oldest element
//which is similar to a queue

template<class Item>
Stack2Queue<Item>::Stack2Queue(){
	used = 0;
}

template<class Item>
void Stack2Queue<Item>::push(const Item& entry){
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	s1.push(entry);
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
	used++;

}

template<class Item>
void Stack2Queue<Item>::pop(){
	assert(!s1.empty());
	s1.pop();
	used--;
}

template<class Item>
Item Stack2Queue<Item>::front() const{
	return s1.top(); //bc not at front
}

template<class Item>
size_t Stack2Queue<Item>::size() const{
	return used;
}

template<class Item>
bool Stack2Queue<Item>::empty() const{
	return (used == 0);
}

#endif