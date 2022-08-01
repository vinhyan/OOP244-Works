/* Final Project Milestone 4
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include <iostream>
#include "Publication.h"



#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H


namespace sdds {
	class Book : public Publication {
		char* m_author;
	public:
		Book();
		Book(const Book& B);
		Book& operator=(const Book& B);
		virtual char type() const;
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
		virtual void set(int membership_id);
		virtual operator bool()const;
		~Book();
	};
}





#endif // !SDDS_BOOK_H
