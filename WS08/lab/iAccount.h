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

#ifndef SDDS_I_ACCOUNT_H
#define SDDS_I_ACCOUNT_H


namespace sdds {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {};
	};
	extern iAccount* CreateAccount(const char*, double);
}


#endif // !SDDS_I_ACCOUNT_H
