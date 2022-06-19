/*
Workshop 05 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 06/20/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Power.h"
#ifndef SDDS_HERO_H
#define SDDS_HERO_H


namespace sdds {
	//const int MAX_NAME_LENGTH = 50;
	//class Power;
	class Hero {
		char m_name[MAX_NAME_LENGTH + 1];
		Power* m_power{};
		int m_num_power{};
		int m_power_level{}; 
	public:
		Hero();
		Hero(const char* name, const Power* power, int num_power);
		~Hero();
		Hero& setEmpty();
		std::ostream& display(std::ostream& ostr) const;
		std::ostream& display() const;
		Hero& operator+=(const Power& power);
		Hero& operator-=(int num);
		bool operator<(const Hero& hero) const;
		bool operator>(const Hero& hero) const;
		void deallocate();
	};

	bool operator>>(const Power& power, Hero& hero);
	bool operator<<(Hero& hero, const Power& power);
	std::ostream& operator<<(std::ostream& ostr, const Hero& hero);
	
}
#endif