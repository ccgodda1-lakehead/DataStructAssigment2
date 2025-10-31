#pragma once
#include "StackArray.h"


/*
okay second try

we need to make sure everything is O(1) above all else
we are not changing the stackarray to make a minstack

we are using stackarray IN minstack


to do this we AREN'T changing how they are being put into a single stack

mainStack will store all the info coming in
while minStack will only store smallest variable in order
thus if you pop it it will go to the next smallest var

*/


class MinStack {
public:

	MinStack(int cap);

	void push(int const x);
	int pop();
	int top() const;
	int get_min() const;

private:
	StackArray<int> *mainStorage;
	StackArray<int> *minStorage;
	int capacity;

};

MinStack::MinStack(int cap)
{
	if (cap <= 0)
		throw string("ERROR: Invalid capacity!");

	capacity = cap;
	mainStorage = new StackArray<int>(cap);
	minStorage = new StackArray<int>(cap);
	
}

void MinStack::push(int const x) {


	//first doing the main push, does have to change anything to thi
	mainStorage->push(x);

	//then we're adding to minstack
	//first checking if it's empty
	if (minStorage->is_empty()) {
		minStorage->push(x);
	}
	//next if it's smaller then the new one
	else if (x <= minStorage->top()) {
		minStorage->push(x);
	}
	//pushing the same top back to make it the same
	else {
		minStorage->push(minStorage->top());
	}
}

int MinStack::pop() {

	if (mainStorage->is_empty())
		throw string("ERROR: Stack underflow!");


	int val = minStorage->top();
	minStorage->pop();
	mainStorage->pop();

	return val;
}

int MinStack::top() const {

	if (mainStorage->is_empty())
		throw string("ERROR: Attempting to retrieve an element from an empty stack!");

	return mainStorage->top();
}

int MinStack::get_min() const {

	if (mainStorage->is_empty())
		throw string("ERROR: Attempting to retrieve an element from an empty stack!");

	return minStorage->top();
}