/*
Workshop 09
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/29/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#include <iostream>
#ifndef SDDS_NAME_H
#define SDDS_NAME_H


namespace sdds {
    class Name {
        char* m_value;
    public:
        Name();
        Name(const char* name);
        Name(const Name& N);
        Name& operator=(const Name& N);
        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
        virtual ~Name();
    };
    std::ostream& operator<<(std::ostream& ostr, const Name& N);
    std::istream& operator>>(std::istream& istr, Name& N);
}


#endif // !SDDS_NAME_H