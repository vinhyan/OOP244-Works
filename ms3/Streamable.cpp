/* Final Project Milestone 3
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {
	
	std::ostream& sdds::operator<<(std::ostream& ostr, const Streamable& stream) {
		if (stream) stream.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Streamable& stream) {
		return stream.read(istr);
	}

}






