/*
11:39 am
2025-10-28
Carson Carolyn Goddard

*/
#include <iostream>
#include "DLL.h"
#include "StackArray.h"

using namespace std;




int main() {

	//declaring Base DLL

	DLList<int> mainDLL;

	DllListFillRandomInt(mainDLL);

	cout << "Starting List: " << mainDLL << endl;

	cout << "Amount of 0 changed to -1: " << replaceVal(mainDLL, 0, -1) << endl;

	cout << "Changed List: " << mainDLL << endl;

	cout << "Removed Negatives: " << mainDLL.rmv_ret_negative() << endl;

	cout << "Changed List: " << mainDLL << endl;

	int remove = 5;

	mainDLL.RemoveAllDuplicatesOf(remove);

	cout << "Removing dups of 5: " << mainDLL << endl;


}