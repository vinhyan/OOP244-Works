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


#ifndef SDDS_SAVING_ACCOUNT_H
#define SDDS_SAVING_ACCOUNT_H


namespace sdds {
	class SavingsAccount : public Account {
		double m_intRate{};
	public:
		SavingsAccount(double accBalance, double intRate);
		void monthEnd();
		void display(std::ostream& ostr) const;
	};
}



#endif // !SDDS_SAVING_ACCOUNT_H