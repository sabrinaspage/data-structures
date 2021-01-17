#ifndef __HW4Q4H__
#define __HW4Q4H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 4 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "hw4q1.h"

using namespace std;

template <class Item>
class Stack2Queue {
    public:
        Stack2Queue();

        void push(const Item& entry);
        void pop();

        size_t size() const;
        bool empty() const;
        Item front() const;

    private:
        Stack<Item> s1; //inbox
        Stack<Item> s2; //outbox
        size_t used;
};

#include "hw4q4.cpp"
#endif