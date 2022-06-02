/*
Workshop 02 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 30, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS


#include <cstdio>
#include "Utils.h"
#include "BirthDate.h"

namespace sdds {

	FILE* fptr;

    //Open data file
	bool openFile(const char* filename) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}

    //Get number of records read from a file
	int getNoOfRecs() {
		int noOfRecs = 0;
		char newline;

		while (fscanf(fptr, "%c", &newline) == 1) {
			noOfRecs += (newline == '\n');
		}

		rewind(fptr);
		return noOfRecs;
	}

    //Close opened file
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	//Read name
	bool read(char* name) {
		bool success = fscanf(fptr, "%[^,],", name);
		return success;
	}

	//Read date
	bool read(BirthDate& birthdate) {
		bool success = fscanf(fptr, "%d/%d/%d\n", &birthdate.month, &birthdate.day,
													 &birthdate.year);
		return success;

	}

}