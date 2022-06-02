/*
Workshop 03 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 06/02/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/



#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H

namespace sdds {

	const int MAX_NAME_LEN = 50;

	class Army {
		char m_nationality[MAX_NAME_LEN]{};
		int m_noOfUnits{};
		double m_power{};
	public:
		//Initializes the Army object to a safe empty state. 
		void setEmpty();

		//Initializes an Army object using arguments passed
		void createArmy(const char* country, double pow, int troops);

		//Updates number of units of an army
		void updateUnits(int troops);

		//Provides nationality of an army
		const char* checkNationality() const;

		//Provides number of troops of an army
		int checkCapacity() const;

		//Provides power of an army
		double checkPower() const;

		//Checks if an army is empty
		bool isEmpty() const;

		//Checks if an army is stronger than another army, returns true if it is, false otherwise
		bool isStrongerThan(const Army& army) const;
	};

	//Lets 2 armies fight and updates the loser's troops
	void battle(Army& arm1, Army& arm2);

	//Displays armies information
	void displayDetails(const Army* armies, int size);

}





#endif // !SDDS_ARMY_H
