/*
Workshop 07
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/15/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#include <iostream>
#include "MemberParliament.h"

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H

namespace sdds {
	const int MAX_PM_NAME_CHAR = 50;
	class Minister : public MemberParliament {
		char m_pm_name[MAX_PM_NAME_CHAR + 1]{};
		double m_office_year{};
	public:
		Minister(const char* id, const int age, const double year, const char* district, 
				 const char* pm_name);
		void changePM(const char* pm);
		void assumeOffice(double year);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os, const Minister& minister);
	std::istream& operator>>(std::istream& in, Minister& minister);
}

#endif // !SDDS_MINISTER_H
