/*
Workshop 04 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 06/12/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_CLEANER_BOT_H
#define SDDS_CLEANER_BOT_H

namespace sdds {

	class CleanerBot {
		char* m_location{};
		double m_battery{};
		int m_brush{};
		bool m_active{};
	public:
		void setEmpty();

		CleanerBot();

		CleanerBot(const char* location, const double battery, const int brush, 
				   const bool active);

		~CleanerBot();

		CleanerBot& set(const char* location, const double battery, 
						const int brush, const bool active);

		void setLocation(const char* location);

		void setActive(const bool active);

		const char* getLocation() const;

		const double getBattery() const;

		const int getBrush() const;

		const bool isActive() const;

		const bool isValid() const;

		void display();

		void deallocate();
	};

	int report(CleanerBot* bot, short num_bots);

	void displayTitle();

	void displayHeader();

	int displayBots(CleanerBot* bot, short num_bots);

	void displayLowBattery(int lowBattery);

	void sortRobots(CleanerBot* bot, short num_bots);

	void displayFooter();
}




#endif // !SDDS_CLEANER_BOT_H
