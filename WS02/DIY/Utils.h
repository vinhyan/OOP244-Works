/*
Workshop 02 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 30, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

	struct BirthDate;

	//Open data file
	bool openFile(const char* filename);

	//Get number of records read from a file
	int getNoOfRecs();

	//Close opened file
	void closeFile();

	//Read name
	bool read(char* name);

	//Read date
	bool read(BirthDate& birthdate);

}



#endif // !SDDS_UTILS_H



