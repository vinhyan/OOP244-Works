/* Final Project Milestone 2
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include "Menu.h"

#ifndef SDDS_LIB_APP_H_
#define SDDS_LIB_APP_H_

namespace sdds {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();
		void save();
		void search();
		void returnPub();
		//Methods with confirmation
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp();
		void run();
	};
}







#endif // !SDDS_LIB_APP_H_
