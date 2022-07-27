
/*
Workshop 09
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/29/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "FullName.h"

namespace sdds {
	FullName::FullName() {
		m_value = nullptr;
	}

	FullName::FullName(const char* name, const char* lastName) : Name(name) {
		delete[] m_value;
		if (lastName && lastName[0] != '\0') {
			m_value = new char[strlen(lastName) + 1];
			strcpy(m_value, lastName);
		}
		else {
			m_value = nullptr;
		}
	}

	FullName::FullName(const FullName& FN) {
		m_value = nullptr;
		*this = FN;
	}

	FullName& FullName::operator=(const FullName& FN) {
		if (this != &FN) {
			Name& name = *this;
			name = FN;
			if (FN.m_value && FN.m_value[0] != '\0') {
				delete[] m_value;
				m_value = new char[strlen(FN.m_value) + 1];
				strcpy(m_value, FN.m_value);
			}
			else {
				m_value = nullptr;
			}
		}
		return *this;
	}

	FullName::operator const char* () const {
		return m_value;
	}

	FullName::operator bool() const {
		return ((m_value && m_value[0] != '\0') && Name::operator bool());
	}

	std::ostream& FullName::display(std::ostream& ostr) const {
		if (m_value && m_value[0] != '\0') {
			Name::display(ostr); 
			ostr << " " << (const char*)*this;
		}
		return ostr;
	}

	std::istream& FullName::read(std::istream& istr) {
		char tmp_fName[256]{};
		Name::read(istr);
		istr.get(tmp_fName, 256);
		if (istr) {
			delete[] m_value;
			m_value = new char[strlen(tmp_fName) + 1];
			strcpy(m_value, tmp_fName);
		}
		istr.ignore();
		return istr;
	}

	FullName::~FullName() {
		delete[] m_value;
	}

	std::ostream& operator<<(std::ostream& ostr, const FullName& FN) {
		return FN.display(ostr);
	}

	std::istream& operator>>(std::istream& istr, FullName& FN) {
		return FN.read(istr);
	}

}