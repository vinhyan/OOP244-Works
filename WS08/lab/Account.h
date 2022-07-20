/*
Workshop 08
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/19/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/



#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

#include "iAccount.h"

namespace sdds {
	class Account : public iAccount {
		double m_currBalance{};
	protected:
		double balance() const;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);
	};
}



#endif // !SDDS_ACCOUNT_H