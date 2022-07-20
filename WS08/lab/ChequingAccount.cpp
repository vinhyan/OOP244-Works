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
#include "ChequingAccount.h"
using namespace std;
namespace sdds {

	ChequingAccount::ChequingAccount(double accBalance, double transaction, 
									 double monthEnd) : Account(accBalance) {
		m_transaction = 0.0;
		m_monthly = 0.0;
		if (transaction > 0.0) m_transaction = transaction;
		if (monthEnd > 0.0) m_monthly = monthEnd;
	}

	bool ChequingAccount::credit(double amount) {
		bool success = Account::credit(amount);
		if (success) Account::debit(m_transaction);
		return success;
	}

	bool ChequingAccount::debit(double amount) {
		bool success = Account::debit(amount);
		if (success) Account::debit(m_transaction);
		return success;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(m_monthly);
	}

	void ChequingAccount::display(std::ostream& ostr) const {
		ostr << "Account type: Chequing" << endl
			 << "Balance: $";
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << balance() << endl
			 << "Per Transaction Fee: " << m_transaction << endl
			 << "Monthly Fee: " << m_monthly << endl;
	}
}