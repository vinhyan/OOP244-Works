/*
Workshop 03 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 06/02/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Army.h"

using namespace std;

namespace sdds {

	//Initializes the Army object to a safe empty state. 
	void Army::setEmpty() {
		m_nationality[0] = '\0';
		m_noOfUnits = 0;
	}

	//Initializes an Army object using arguments passed
	void Army::createArmy(const char* country, double pow, int troops) {
		bool valid = (country != nullptr && strlen(country) > 0 && 
					  troops > 0 && pow > 0);
		
		if (valid) {
			strcpy(m_nationality, country);
			m_noOfUnits = troops;
			m_power = pow;
		}
		else {
			setEmpty();
		}
	}

	//Updates number of units of an army
	void Army::updateUnits(int troops) {
		m_noOfUnits += troops;
		m_power += troops * 0.25;
	}

	//Provides nationality of an army
	const char* Army::checkNationality() const {
		return m_nationality;
	}

	//Provides number of troops of an army
	int Army::checkCapacity() const {
		return m_noOfUnits;
	}

	//Provides power of an army
	double Army::checkPower() const {
		return m_power;
	}

	//Checks if an army is empty
	bool Army::isEmpty() const {
		bool empty{};
		if (!(m_nationality && m_noOfUnits)) empty = true;

		return empty;
	}

	//Checks if an army is stronger than another army, returns true if it is, false otherwise
	bool Army::isStrongerThan(const Army& army) const {
		bool isStronger = m_power > army.m_power;
		return isStronger;
	}

	//Lets 2 armies fight and updates the loser's troops
	void battle(Army& arm1, Army& arm2) {

		bool isWinner{};

		cout << "In battle of " << arm1.checkNationality() << " and " 
								<< arm2.checkNationality() << ", ";

		if (arm1.checkNationality() && arm1.checkCapacity() &&
			arm2.checkNationality() && arm2.checkCapacity()) {

			//Check if arm1 is the winner
			isWinner = arm1.isStrongerThan(arm2);

			if (isWinner) {
				arm2.updateUnits(int(-(arm2.checkCapacity() * 0.5)));

				cout << arm1.checkNationality() << " is victorious!" << endl;
			}
			else {
				arm1.updateUnits(int(-(arm1.checkCapacity() * 0.5)));

				cout << arm2.checkNationality() << " is victorious!" << endl;
			}
		}
	}

	//Displays armies information
	void displayDetails(const Army* armies, int size) {
		cout << "Armies reporting to battle: " << endl;

		for (int i = 0; i < size; i++) {
			if (!armies[i].isEmpty()) {
				cout.setf(ios::fixed);
				cout.precision(1);
				cout << "Nationality: " << armies[i].checkNationality() << ", "
					 << "Units Count: " << armies[i].checkCapacity() << ", "
					 << "Power left: "  << armies[i].checkPower() << endl;
			}
		}
	}

}

