#ifndef __HW4Q1_H__
#define __HW4Q1_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 4 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

template <class Item>
class Stack {
	private:
        size_t used;
        size_t capacity;
        Item* data;
    public:
        const size_t DEF_CAP = 30;

        Stack() {
        	capacity = DEF_CAP;
        	data = new Item[capacity];
        	used = 0;
        };
        Stack(const Stack& source);
        ~Stack();

        void push(const Item& entry);
        void pop();
        void operator=(const Stack<Item>& source);

        size_t size() const { return used; }
        bool empty() const { return(used==0); }
        Item top() const;
};

#include "hw4q1.cpp"
#endif