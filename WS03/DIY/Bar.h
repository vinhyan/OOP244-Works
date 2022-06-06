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
		//Sets Bar to empty state
		void setEmpty();

		//Sets Bar title, fill character, value of the bar. Sets Bar to empty state if any argument is invalid
		void set(const char* title, char fillChar, int val);

		//Returns if the Bar is valid or not
		bool isValid();

		//Draws a bar based on its data
		void draw() const;


	};




}




#endif // !SDDS_BAR_H



