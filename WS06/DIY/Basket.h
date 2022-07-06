/*
Workshop 06 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/05/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#include <iostream>

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

namespace sdds {
	struct Fruit {
		char m_name[30 + 1];
		double m_qty;
	};

	class Basket {
		Fruit* m_fruits{};
		int m_cnt{};
		double m_price{};
	public:
		Basket();
		Basket(const Fruit* fruits, int size, double price);
		Basket(const Basket& basket);
		Basket& operator=(const Basket& basket);
		void setPrice(double price);
		operator bool()const;
		Basket& operator+=(const Fruit fruit);
		friend std::ostream& operator<<(std::ostream& ostr, const Basket& bastet);
		~Basket();
	};
}



#endif // !SDDS_BASKET_H



