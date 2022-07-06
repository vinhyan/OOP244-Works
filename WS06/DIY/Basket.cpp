/*
Workshop 06 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/05/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#include "Basket.h"

using namespace std;

namespace sdds {
	Basket::Basket() {
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}

	Basket::Basket(const Fruit* fruits, int size, double price) {
		if (fruits && size && price) {
			delete[] m_fruits;
			m_cnt = size;
			m_price = price;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = fruits[i];
			}
		}
	}

	Basket::Basket(const Basket& basket) {
		*this = basket;
	}

	Basket& Basket::operator=(const Basket& basket) {
		if (this != &basket) {
			delete[] m_fruits;
			m_cnt = basket.m_cnt;
			m_price = basket.m_price;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = basket.m_fruits[i];
			}
		}
		return *this;
	}

	void Basket::setPrice(double price) {
		m_price = price;
	}

	Basket::operator bool() const {
		return m_cnt > 0;
	}

	Basket& Basket::operator+=(const Fruit fruit) {
		Fruit* temp{};
		temp = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; i++) {
			temp[i] = m_fruits[i];
		}
		temp[m_cnt] = fruit;
		delete[] m_fruits;
		m_fruits = temp;
		m_cnt++;
		return *this;
	}

	Basket::~Basket() {
		delete[] m_fruits;
	}

	std::ostream& operator<<(std::ostream& ostr, const Basket& basket) {
		if (basket.m_cnt == 0) {
			ostr << "The basket is empty!" << endl;
		}
		else {
			ostr << "Basket Content:" << endl;
			for (int i = 0; i < basket.m_cnt; i++) {
				ostr.width(10);
				ostr.setf(ios::right);
				ostr << basket.m_fruits[i].m_name;
				ostr.unsetf(ios::right);
				ostr << ": ";
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << basket.m_fruits[i].m_qty << "kg" << endl;
			}
			ostr << "Price: " << basket.m_price << endl;
		}
		return ostr;
	}

}