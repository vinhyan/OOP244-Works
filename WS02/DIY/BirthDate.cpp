/*
Workshop 02 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 26, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
#include "BirthDate.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	Employee* employees{};
	Employee* bdayEmployees{};
	int noOfRecs = 0;
	int noOfBdayEmp = 0;
	
	
	//Opens the datafile. If successful it will print 'Birthdate search program' and returns 
	//true otherwise it will print 'Data file "filename goes here" not found!' and return false;
	bool beginSearch(const char* filename) {
		bool success = openFile(filename);

		if (success) {
			
			load();
			cout << "Birthdate search program" << endl;

			closeFile();
		}
		else {
			cout << "Data file " << filename << " not found!" << endl;
		}

		return success;
	}

	//load data of one employee
	bool load(Employee& employee) {
		char name[31]{};
		bool success = false;

		if (read(name) && read(employee.m_birthdate)) {
			employee.m_name = new char[strlen(name) + 1];
			strcpy(employee.m_name, name);

			success = true;
		}

		return success;
	}

	//load all employee data
	bool load() {
		int i = 0;
		bool success = true;

		noOfRecs = getNoOfRecs();

		employees = new Employee[noOfRecs];

		for (i = 0; i < noOfRecs; i++) {
			load(employees[i]);
		}

		if (i != noOfRecs) {
			cout << "Error: incorrect number of records read; the data is possibly corrupted." 
				 << endl;
			success = false;
		}
		
		return success;

	}

	//Reads the birth records matching the month. If at least one record is matched and read,
	//turns true, otherwise false
	bool readBirthDate(int month) {
		bool success = true;

		bdayEmployees = new Employee[noOfRecs];

		for (int i = 0; i < noOfRecs; i++) {
			if (employees[i].m_birthdate.month == month) {
				bdayEmployees[noOfBdayEmp] = employees[i];
				noOfBdayEmp++;
			}
		}

		if (!noOfBdayEmp) success = false;

		return success;
	}

	//Sorts the records based on the year of birth in descending order.
	void sort() {
		int i, j;
		Employee temp;
		for (i = noOfBdayEmp - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (bdayEmployees[j].m_birthdate.year > bdayEmployees[j + 1].m_birthdate.year) {
					temp = bdayEmployees[j];
					bdayEmployees[j] = bdayEmployees[j + 1];
					bdayEmployees[j + 1] = temp;
				}
			}
		}
	}

	//Displays the found records as displayed in thse execution sample.
	void displayBirthdays() {
		cout << noOfBdayEmp << " birthdates found:" << endl;
		for (int i = 0; i < noOfBdayEmp; i++) {
			cout << i + 1 << ") "
				 << bdayEmployees[i].m_name << ":" << "\n"
				 << bdayEmployees[i].m_birthdate.year << "-"
				 << bdayEmployees[i].m_birthdate.month << "-"
				 << bdayEmployees[i].m_birthdate.day << "\n"
				 << "===================================" << endl;
		}
	}

	//Releases all the dynamically allocated memory.
	void deallocate() {
		for (int i = 0; i < noOfRecs; i++) {
			delete[] employees[i].m_name;
		}

		delete[] employees;
		delete[] bdayEmployees;
	}

	//Finalizes the program by making sure all resources are released and closed and then 
	//prints: Birthdate Search Program Closed.
	void endSearch() {
		cout << "Birthdate Search Program Closed." << endl;
	}

}