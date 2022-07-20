/*
Workshop 08
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/19/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Account.h"

namespace sdds {
	double Account::balance() const {
		return m_currBalance;
	}
	Account::Account(double accBalance) {
		m_currBalance = 0.0;
		if (accBalance > 0.0) m_currBalance = accBalance;
	}

	bool Account::credit(double amount) {
		bool success{};
		if (amount > 0.0) {
			m_currBalance += amount;
			success = true;
		}
		return success;
	}

	bool Account::debit(double amount) {
		bool success{};
		if (amount > 0.0) {
			m_currBalance -= amount;
			success = true;
		}
		return success;
	}
}