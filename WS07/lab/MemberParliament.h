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

#ifndef SDDS_MEMBER_PARLIAMENT_H
#define SDDS_MEMBER_PARLIAMENT_H

namespace sdds {
	const int MAX_ID_CHAR = 32;
	const int MAX_DISTRICT_CHAR = 64;
	class MemberParliament {
		char m_id[MAX_ID_CHAR + 1]{};
		char m_district[MAX_DISTRICT_CHAR + 1]{};
		int m_age{};
	public:
		MemberParliament(const char* id, const int age);
		void NewDistrict(const char* district);
		bool setIdAndAge(const char* id, const int age);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os, const MemberParliament& MP);
	std::istream& operator>>(std::istream& in, MemberParliament& MP);
}

#endif // !SDDS_MEMBER_PARLIAMENT_H
