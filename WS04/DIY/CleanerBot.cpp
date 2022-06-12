/*
Workshop 04 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 06/12/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<iomanip>
#include <string.h>
#include <cctype>
#include "CleanerBot.h"

using namespace std;

namespace sdds {
	void CleanerBot::setEmpty() {
		m_location = nullptr;
		m_battery = 0.0;
		m_brush = 0;
		m_active = false;
	}

	CleanerBot::CleanerBot() {
		setEmpty();
	}

	CleanerBot::CleanerBot(const char* location, const double battery, const int brush, 
						   const bool active) {
		set(location, battery, brush, active);
	}
	CleanerBot::~CleanerBot() {
		deallocate();
	}

	CleanerBot& CleanerBot::set(const char* location, const double battery, const int brush, 
								const bool active) {
		deallocate();
		setLocation(location);
		setActive(active);
		m_brush = brush;
		m_battery = battery;

		return *this;
	}

	void CleanerBot::setLocation(const char* location) {
		if (location && location[0]) {
			m_location = new char[strlen(location) + 1];
			strcpy(m_location, location); // DELETE DMA
		}
	}

	void CleanerBot::setActive(bool active) {
		m_active = active;
	}

	const char* CleanerBot::getLocation() const {
		return m_location;
	}

	const double CleanerBot::getBattery() const {
		return m_battery;
	}

	const int CleanerBot::getBrush() const {
		return m_brush;
	}

	const bool CleanerBot::isActive() const {
		return m_active;
	}

	const bool CleanerBot::isValid() const {
		return (m_location && m_location[0]) && m_battery > 0;
	}

	void CleanerBot::display() {
		char* yesNo{};
		yesNo = new char[4];    
		if (m_active) {
			strcpy(yesNo, "YES");
		}
		else {
			strcpy(yesNo, "NO");
		}
		cout << "| ";
		cout.width(11);
		cout.setf(ios::left); 
		cout << m_location << "| ";
		cout.width(7);
		cout.unsetf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << m_battery << " | ";
		cout.width(18);
		cout << m_brush << " | ";
		cout.width(6);
		cout.setf(ios::left);
		cout << yesNo << " |" << endl;

		delete[] yesNo;
		yesNo = nullptr;
	}

	void CleanerBot::deallocate() {
		delete[] m_location;
		m_location = nullptr;
	}

	int report(CleanerBot* bot, short num_bots) {
		int lowBattery = 0;
		displayTitle();
		displayHeader();

		lowBattery = displayBots(bot, num_bots);

		cout << endl;

		if (lowBattery) {
			displayLowBattery(lowBattery);
			sortRobots(bot, num_bots);
			displayBots(bot, num_bots);
		}

		displayFooter();

		return 0;
	}

	void displayTitle() {
		cout << setw(41) << "------ Cleaner Bots Report -----" << endl;
		cout << setw(44) << "---------------------------------------" << endl;
		
	}

	void displayHeader() {
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;

	}

	int displayBots(CleanerBot* bot, short num_bots) {
		int lowBattery = 0;
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				bot[i].display();
				lowBattery += (bot[i].getBattery() < 30);
			}
		}
		return lowBattery;
	}

	void displayLowBattery(int lowBattery) {
		cout << "|====================================================|" << endl;
		cout << "| LOW BATTERY WARNING :                              |" << endl;
		cout << "|====================================================|" << endl;
		cout << "| Number of robots to be charged: "; 
		cout << lowBattery << "                  |" << endl;
		cout << "| Sorting robots based on their available power:     |" << endl;
		displayHeader();
	}

	void sortRobots(CleanerBot* bot, short num_bots) {
		CleanerBot temp{};
		int idx = 0;
		int j = 0;
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				idx = i;
				for (j = i; j < num_bots; j++) {
					if (bot[j].getBattery() > bot[idx].getBattery()) {
						idx = j;

					}
				}

				if (idx != i) {
					temp.set(bot[i].getLocation(), bot[i].getBattery(), bot[i].getBrush(), 
							 bot[i].isActive());
					bot[i].set(bot[idx].getLocation(), bot[idx].getBattery(), bot[idx].getBrush(), 
							   bot[idx].isActive());
					bot[idx].set(temp.getLocation(), temp.getBattery(), temp.getBrush(), 
								 temp.isActive());
				}
			}
		}
	}

	void displayFooter() {
		cout << "|====================================================|" << endl;
	}
}