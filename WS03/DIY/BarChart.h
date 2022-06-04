/*
Workshop 03 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : June 5, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H

namespace sdds {
	class Bar;
	class BarChart {
		char* m_title{};
		Bar* m_bars{};
		char m_fillChar{};
		int m_numOfBars{};
		int m_numOfAddedVal{};
	public:
		bool validate() const;

		void init(const char* title, int noOfSamples, char fill);

		void add(const char* bar_title, int value);

		void draw() const;

		void deallocate();
	};

	void printDashLine(int numOfDash);

}




#endif // !SDDS_BARCHART


