/*
Workshop 04 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        :

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Car.h"

using namespace std;

namespace sdds {
	void Car::resetInfo() {
		m_type = m_brand = m_model = nullptr;
		m_year = m_code = 0;
		m_price = 0.0;
	}

	void Car::deallocate() {
		delete m_type;
		m_type = nullptr;
		delete m_brand;
		m_brand = nullptr;
		delete m_model;
		m_model = nullptr;
	}

	Car::Car() {
		resetInfo();
	}

	Car::Car(const char* type, const char* brand, const char* model, 
			 int year, int code, double price) {
		setInfo(type, brand, model, year, code, price);
	}

	Car::~Car() {
		deallocate();
	}

	Car& Car::setInfo(const char* type, const char* brand, const char* model, 
					  int year, int code, double price) {
		// TODO: insert return statement here
		deallocate();

		if (isStrValid(type) && isStrValid(brand) && isStrValid(model) &&
			(year >= 1990) && (code > 99 && code < 1000) && (price > 0)) {

			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];

			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
		return *this;
	}

	void Car::printInfo() const {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(10);
		cout << m_type;
		cout << " |";

		cout << " ";
		cout.width(16);
		cout << m_brand; 
		cout << " ";
		
		cout << "| ";
		cout.width(16);
		cout << m_model;
		cout << " |";

		cout.unsetf(ios::left);
		cout << " ";
		cout.width(4);
		cout << m_year << " ";

		cout << "| ";
		cout.width(4);
		cout << m_code;
		cout << " |";

		cout << " ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(9);
		cout << m_price;
		cout << " |" << endl;
	}

	bool Car::isValid() const {
		return (isStrValid(m_type) && isStrValid(m_brand) && isStrValid(m_model) &&
				(m_year >= 1990) && (m_code > 99 && m_code < 1000) && (m_price > 0));
	}

	bool Car::isSimilarTo(const Car& car) const {
		//need to check if the object valid
		return (this->m_brand == car.m_brand && this->m_model == car.m_model &&
			this->m_type == car.m_type && this->m_year == car.m_year);
	}

	bool isStrValid(const char* str) {
		return (str && str[0]);
	}

	
	bool has_similar(const Car car[], const int num_cars) {
		bool isMatched = false;

		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					isMatched = true;
				}
			}
		}
		return isMatched;
	}

	bool has_invalid(const Car car[], const int num_cars) {
		int invalidCount = 0;
		for (int i = 0; i < num_cars; i++) {
			invalidCount += (!car[i].isValid());
		}
		return !!invalidCount;
	}

	void print(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			if (car[i].isValid()) {
				car[i].printInfo();
			}
		}
	}
}