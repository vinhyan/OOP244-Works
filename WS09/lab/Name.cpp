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

#include <iostream>
#include <cstring>
#include "Name.h"

namespace sdds {
	Name::Name() {
		m_value = nullptr;
	}
	Name::Name(const char* name) {
		delete[] m_value;
		if (name && name[0] != '\0') {
			m_value = new char[strlen(name) + 1];
			strcpy(m_value, name);
		}
		else {
			m_value = nullptr;
		}
	}
	Name::Name(const Name& N) {
		*this = N;
	}
	Name& Name::operator=(const Name& N) {
		if (this != &N) {
			if (N.m_value && N.m_value[0] != '\0') {
				delete[] m_value;
				m_value = new char[strlen(N.m_value) + 1];
				strcpy(m_value, N.m_value);
			}
			else {
				m_value = nullptr;
			}
		}
		return *this;
	}
	Name::operator const char* () const {
		return m_value;
	}
	Name::operator bool() const {
		return (m_value && m_value[0] != '\0');
	}
	std::ostream& Name::display(std::ostream& ostr) const {
		if (*this) ostr << (const char*)*this;
		return ostr;
	}
	std::istream& Name::read(std::istream& istr) {
		char tmp_name[256]{};
		istr.get(tmp_name, 256, ' ');
		if (istr) {
			delete[] m_value;
			m_value = new char[strlen(tmp_name) + 1];
			strcpy(m_value, tmp_name);
		}
		istr.ignore();
		return istr;
	}
	Name::~Name() {
		delete[] m_value;
	}
	std::ostream& operator<<(std::ostream& ostr, const Name& N) {
		return N.display(ostr);
	}
	std::istream& operator>>(std::istream& istr, Name& N) {
		return N.read(istr);
	}
}