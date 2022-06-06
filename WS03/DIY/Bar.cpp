/*
Workshop 03 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : June 5, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Bar.h"


using namespace std;

namespace sdds {

	//Sets Bar to empty state
	void Bar::setEmpty() {
		m_title[0] = '\0';
		m_fillChar = 0;
		m_sampleVal = 0;
	}

	//Sets Bar title, fill character, value of the bar. Sets Bar to empty state if any argument is invalid
	void Bar::set(const char* title, char fillChar, int val) {
		
		if (!(val < 0 || val > 100)) {
			strcpy(m_title, title);
			m_fillChar = fillChar;
			m_sampleVal = val;
		}
		else {
			setEmpty();
		}
	}

	//Returns if the Bar is valid or not
	bool Bar::isValid() {
		return !!m_sampleVal;
	}

	//Draws a bar based on its data
	void Bar::draw() const {

		if (m_sampleVal) {
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_title << "|";

			for (int i = 0; i < int(m_sampleVal / 2); i++) {
				cout << m_fillChar;
			};
			cout << endl;
		}
		
	}
}