/*
Workshop 07
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/15/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Minister.h"

using namespace std;
namespace sdds {
	Minister::Minister(const char* id, const int age, const double year, const char* pm_name,
					   const char* district) : MemberParliament(id, age) {
		MemberParliament::NewDistrict(district);
		changePM(pm_name);
		assumeOffice(year);

	}
	void Minister::changePM(const char* pm) {
		if (pm && pm[0] != '\0') {
			strncpy(m_pm_name, pm, MAX_PM_NAME_CHAR);
			m_pm_name[MAX_PM_NAME_CHAR] = '\0';
		}
	}
	void Minister::assumeOffice(double year) {
		if (year) m_office_year = year;
	}
	std::ostream& Minister::write(std::ostream& os) const {
		MemberParliament::write(os) << " | " << m_pm_name << "/" << m_office_year;
		return os;
	}
	std::istream& Minister::read(std::istream& in) {
		bool done{};
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in.getline(m_pm_name, MAX_PM_NAME_CHAR);
		cout << "Year Assumed Office: ";
		while (!done) {
			in >> m_office_year;
			if (in.fail()) {
				done = false;
				cout << "Please enter a number: ";
				in.clear();
				in.ignore(1000, '\n');
			}
			else {
				done = true;
			}
		}
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Minister& minister) {
		return minister.write(os);
	}

	std::istream& operator>>(std::istream& in, Minister& minister) {
		return minister.read(in);
	}

}
