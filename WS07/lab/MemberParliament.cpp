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
#include "MemberParliament.h"

using namespace std;
namespace sdds {
	MemberParliament::MemberParliament(const char* id, const int age) {
		if (setIdAndAge(id, age)) {
			strcpy(m_district, "Unassigned");
		}
	}
	void MemberParliament::NewDistrict(const char* district) {
		if (district && district[0] != '\0') {
			//display id and current district
			cout << "|";
			cout.width(8); 
			cout.setf(ios::right);
			cout << m_id << "| |";
			cout.width(20);
			cout << m_district << " ---> ";
			//assign new district
			strncpy(m_district, district, MAX_DISTRICT_CHAR);
			m_district[MAX_DISTRICT_CHAR] = '\0';
			//display new district
			cout.width(23);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << m_district << "|" << endl;
		}
	}

	bool MemberParliament::setIdAndAge(const char* id, const int age) {
		bool status{};
		if (id && id[0] != '\0' && age) {
			strncpy(m_id, id, MAX_ID_CHAR);
			m_id[MAX_ID_CHAR] = '\0';
			m_age = age;
			status = true;
		}
		else {
			status = false;
		}
		return status;
	}

	std::ostream& MemberParliament::write(std::ostream& os = cout) const {
		os << "| " << m_id << " | " << m_age << " | " << m_district;
		return os;
	}

	std::istream& MemberParliament::read(std::istream& in) {
		bool done{};
		cout << "Age: ";
		while (!done) {
			in >> m_age;
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
		in.ignore(1000, '\n');
		cout << "Id: ";
		in.getline(m_id, MAX_ID_CHAR);
		cout << "District: ";
		in.getline(m_district, MAX_DISTRICT_CHAR);
		return in;
	}
	
	std::ostream& operator<<(std::ostream& os, const MemberParliament& MP) {
		return MP.write(os);
	}

	std::istream& operator>>(std::istream& in, MemberParliament& MP) {
		return MP.read(in);
	}
}