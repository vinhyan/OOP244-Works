/* Final Project Milestone 4
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/


#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& iostr) const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const Streamable& stream);
	std::istream& operator>>(std::istream& istr, Streamable& stream);
}




#endif // !SDDS_STREAMABLE_H
