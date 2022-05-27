/*
Workshop 02 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 26, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H

namespace sdds {

	struct BirthDate {
		int day;
		int month;
		int year;
	};

	struct Employee {
		char* m_name;
		BirthDate m_birthdate{};
	};

	//Opens the datafile. If successful it will print Birthdate search program and returns 
	//true otherwise it will print Data file "filename goes here" not found! and return false;
	bool beginSearch(const char* filename);

	//load data of one employee
	bool load(Employee& employee);

	//load all employee data
	bool load();

	//Reads the birth records matching the month. If at least one record is matched and read,
	//turns true, otherwise false
	bool readBirthDate(int month);

	//Sorts the records based on the year of birth in descending order.
	void sort();

	//Displays the found records as displayed in the execution sample.
	void displayBirthdays();

	//Releases all the dynamically allocated memory.
	void deallocate();

	//Finalizes the program by making sure all resources are released and closed and then 
	//prints: Birthdate Search Program Closed
	void endSearch();
}


#endif // !SDDS_BIRTHDATE_H
