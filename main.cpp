/*
11:39 am
2025-10-28
Carson Carolyn Goddard

*/
#include <iostream>
#include "DLL.h"
#include "MinStack.h"

using namespace std;




int main() {

	//declaring Base DLL

	DLList<int> mainDLL;

	DllListFillRandomInt(mainDLL);

	cout << "Starting List: " << mainDLL << endl;

	//Section A Task 1
	cout << "Amount of 0 changed to -1: " << replaceVal(mainDLL, 0, -1) << endl;

	cout << "Changed List: " << mainDLL << endl;

	//Section A task 2
	cout << "Removed Negatives: " << mainDLL.rmv_ret_negative() << endl;

	cout << "Changed List: " << mainDLL << endl;

	//Section A task 3
	int remove = 5;

	mainDLL.RemoveAllDuplicatesOf(remove);

	cout << "Removing duplicates of 5: " << mainDLL << endl;

	//getting random variable
	srand(time(0));

	int ranIndex = rand() % mainDLL.getSize();

	//Section A task 4
	cout << "getting variable at index " << ranIndex << ": [" << mainDLL.get_at(ranIndex)->get_val() << "]" << endl;

	int value = 200;

	//Section A task 5
	mainDLL.insert_before(ranIndex, value);

	cout << "Inserting 200 before that index: " << mainDLL << endl;


	cout << endl << "-------------------" << endl;


	//stack testing here.

	//need to make sure we're adding things smaller then the min before it
	//and larger




	

}