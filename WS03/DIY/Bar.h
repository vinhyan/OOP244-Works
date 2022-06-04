/*
Workshop 03 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : June 5, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BAR_H
#define SDDSD_BAR_H




namespace sdds {

	const int MAX_TITLE_CHAR = 20;

	class Bar {
		char m_title[MAX_TITLE_CHAR + 1]{};
		char m_fillChar{};
		int m_sampleVal{};
	public:
		void setEmpty();

		void set(const char* title, char fillChar, int val);

		bool isValid();

		void draw() const;


	};




}




#endif // !SDDS_BAR_H



