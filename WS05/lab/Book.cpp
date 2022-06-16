/*
Workshop 05 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 06/17/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	int Book::add_chapter(Chapter* chapter) {
		if (m_num_chapters < MAX_NUM_CHAPTERS) {
			m_chapters[m_num_chapters] = *chapter;
			m_num_pages += (int)m_chapters[m_num_chapters];
			(*this)++;
			
		}
		return m_num_chapters;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

	Book Book::operator++(int) {
		Book book = *this;
		m_num_chapters += 1;
		return book;
	}

	std::ostream& Book::display(std::ostream& os) const {
		cout << "Title:'" << m_title << "'" << endl;
		cout << "Author: '" << m_author << "'" << endl;
		for (int i = 0; i < m_num_chapters; i++) {
			m_chapters[i].display(os);
		}
		return os;
	}

	Book::operator int() const {
		return m_num_chapters;
	}

	Book::operator bool() const {
		int count = 0;
		for (int i = 0; i < m_num_chapters; i++) {
			if ((int)m_chapters[i] > 0) count++;
		}
		return (m_title && m_author && m_num_chapters && (count > 0));
	}

	Book::operator double() const {
		return m_price;
	}

	Book::operator const char* () const {
		return m_title;
	}

	bool Book::operator!() const{
		return !(bool)*this;
	}

	Book& Book::operator+=(Chapter chapter) {
		add_chapter(&chapter);
		return *this;
	
	}

	Book& Book::operator-=(double discount) {
		if (discount <= m_price) m_price -= discount;
		return *this;
	}

	std::ostream& operator<<(std::ostream& left, const Book& book) {
		return book.display(left);
	}

}
