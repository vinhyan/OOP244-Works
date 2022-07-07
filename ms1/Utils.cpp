/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version 1.0
// Date 07/06/2022
// Author Vinh Nhan
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "Utils.h"


namespace sdds {
	int selectOption(unsigned int min, unsigned int max) {
		unsigned int select{};
		bool done{};
		while (!done) {
			cin >> select;
			if (cin.fail() || !(select >= min && select <= max)) {
				done = false;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
			}
			else {
				done = true;
			}
		}
		cin.ignore(1000, '\n');
		return select;
	}
}