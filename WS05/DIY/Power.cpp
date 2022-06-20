/*
Workshop 05 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 06/20/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Power.h"

using namespace std;

namespace sdds {

	Power::Power() {
		this->setEmpty();
	}
	Power::Power(const char* name, int rarity) {
		this->createPower(name, rarity);
	}
	void Power::setEmpty() {
		m_name[0] = '\0';
		m_rarity = 0;
	}
	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0) {
			strncpy(this->m_name, name, MAX_NAME_LENGTH);
			this->m_rarity = rarity;
		}
		else {
			this->setEmpty();
		}
	}

	Power& Power::operator=(const Power& power) {
		createPower(power.checkName(), power.checkRarity());
		return *this;
	}
	
	const char* Power::checkName() const {
		return m_name;
	}
	int Power::checkRarity() const {
		return m_rarity;
	}
	bool Power::isEmpty() const {
		return (m_name[0] == '\0' || m_rarity == 0 );
	}
	void displayDetails(Power* powers, int size) {
		cout << "List of available powers: " << endl;
		for (int i = 0; i < size; i++) {
			if (!powers[i].isEmpty()) {
				cout << "  Name: " << powers[i].checkName() << ", "
					<< "Rarity: " << powers[i].checkRarity() << endl;
			}
		}
	}
}