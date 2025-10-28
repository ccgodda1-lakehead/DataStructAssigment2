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

	cout << "Amount of 0 changed to 20: " << replaceVal(mainDLL, 0, 20) << endl;

	cout << "Changed List: " << mainDLL;

}