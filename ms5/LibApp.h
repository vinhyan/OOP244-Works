/* Final Project Milestone 5
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#include "Publication.h"
#include "Menu.h"


#ifndef SDDS_LIB_APP_H
#define SDDS_LIB_APP_H


namespace sdds {
	class LibApp {
		char m_filename[256]{};
		Publication* m_pubs[SDDS_LIBRARY_CAPACITY]{};   //PPA
		int m_numOfPub{};    //NOLP
		int m_lastRefNum{};   //LLRN
		Menu m_pubMenu;
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();
		void save();
		int search(int searchMode);
		void returnPub();
		//Methods with confirmation
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp(const char* filename);
		void run();
		Publication* getPub(int libRef);
		virtual ~LibApp();
	};
}






#endif // !SDDS_LIB_APP_H