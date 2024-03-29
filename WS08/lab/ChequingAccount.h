/*
Workshop 08
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/19/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Account.h"

#ifndef SDDS_CHEQUING_ACCOUNT_H
#define SDDS_CHEQUING_ACCOUNT_H


namespace sdds {
	class ChequingAccount : public Account {
		double m_transaction{};
		double m_monthly{};
	public:
		ChequingAccount(double accBalance, double transaction, double monthEnd);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& ostr) const;
	};
}



#endif // !SDDS_CHEQUING_ACCOUNT_H