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

#include <iostream>
#include <string.h>
#include "Hero.h"
#include "Power.h"

using namespace std;

namespace sdds {
	Hero::Hero() {
		setEmpty();
	}

	Hero::Hero(const char* name, const Power* power, int num_power) {
		int totalRarity = 0;
		setEmpty();
		strcpy(m_name, name);
		m_num_power = num_power;
		m_power = new Power[num_power];
		for (int i = 0; i < num_power; i++) {
			m_power[i] = power[i];
			totalRarity += m_power[i].checkRarity();
		}
		m_power_level = totalRarity * m_num_power;
	}

	Hero::~Hero() {
		deallocate();
	}

	Hero& Hero::setEmpty() {
		m_name[0] = '\0';
		m_power = nullptr;
		m_num_power = 0;
		m_power_level = 0;
		return *this;
	}

	//This function does not get accepted by Matrix submitter
	std::ostream& Hero::display(std::ostream& ostr) const{
		ostr << "Name: " << m_name << endl;
		ostr << "List of available powers: " << endl;
		for (int i = 0; i < m_num_power; i++) {
			ostr << "  Name: " << m_power[i].checkName() << ", "
				 << "Rarity: " << m_power[i].checkRarity() << endl;
		}
		ostr << "Power Level: " << m_power_level;
		return ostr;
	}

	//Replacement for the above function
	std::ostream& Hero::display() const {
		cout << "Name: " << m_name << endl;
		cout << "List of available powers: " << endl;
		for (int i = 0; i < m_num_power; i++) {
			cout << "  Name: " << m_power[i].checkName() << ", "
				 << "Rarity: " << m_power[i].checkRarity() << endl;
		}
		cout << "Power Level: " << m_power_level;
		return cout;
	}

	Hero& Hero::operator+=(const Power& power) {
		Power* temp{};
		int totalRarity = 0;

		//temp = new Power[m_num_power];
		//for (int i = 0; i < m_num_power; i++) {
		//	temp[i] = m_power[i];
		//}
		//
		//deallocate();

		//m_power = new Power[m_num_power + 1];
		//for (int i = 0; i < m_num_power; i++) {
		//	m_power[i] = temp[i];
		//	totalRarity += m_power[i].checkRarity();
		//}

		//delete[] temp;

		//m_power[m_num_power] = power;

		//totalRarity += m_power[m_num_power].checkRarity();

		//m_power_level = totalRarity * (m_num_power + 1);
		//m_num_power++;
		temp = new Power[m_num_power + 1];
		temp = m_power;
		temp[m_num_power] = power;
		delete[] m_power;
		m_power = temp;



		return *this;
	}

	Hero& Hero::operator-=(int num) {
		m_power_level -= num;
		return *this;
	}

	bool Hero::operator<(const Hero& hero) const {
		return m_power_level < hero.m_power_level;
	}

	bool Hero::operator>(const Hero& hero) const {
		return m_power_level > hero.m_power_level;
	}

	void Hero::deallocate() {
		delete[] m_power;
		m_power = nullptr;
 	}

	bool operator>>(const Power& power, Hero& hero) {
		hero += power;
		return true;
	}

	bool operator<<(Hero& hero, const Power& power) {
		hero += power;
		return true;
	}

	std::ostream& operator<<(std::ostream& ostr, const Hero& hero) {
		hero.display(ostr);
		return ostr;
	}

}