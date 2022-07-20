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
#include "SavingsAccount.h"

using namespace std;
namespace sdds {
	SavingsAccount::SavingsAccount(double accBalance, double intRate) 
		: Account(accBalance) {
		m_intRate = 0.0;
		if (intRate > 0.0) m_intRate = intRate;
	}
	void SavingsAccount::monthEnd() {
		credit(balance() * m_intRate);
	}
	void SavingsAccount::display(std::ostream& ostr) const {
		ostr << "Account type: Savings" << endl
			 << "Balance: $";
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << balance() << endl << "Interest Rate (%): " 
			 << m_intRate * 100.0 << endl;
	}
}