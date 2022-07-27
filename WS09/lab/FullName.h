/*
Workshop 09
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/29/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Name.h"
#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H


namespace sdds {
    class FullName : public Name {
        char* m_value;
    public:
        FullName();
        FullName(const char* name, const char* lastName);
        // Rule of three goes here:
        FullName(const FullName& FN);
        FullName& operator=(const FullName& FN);
        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
        virtual ~FullName();
    };
    std::ostream& operator<<(std::ostream& ostr, const FullName& FN);
    std::istream& operator>>(std::istream& istr, FullName& FN);

}


#endif // !SDDS_FULLNAME_H
