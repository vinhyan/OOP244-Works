/* Final Project Milestone 2
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include <iostream>
#include "LibApp.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message) {
		Menu confirm(message);
		confirm << "Yes";
		return !!(~confirm);
	}
	void LibApp::load() {
		cout << "Loading Data" << endl;
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
	}
	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub() {
		search();
		cout << "Returning Publication" << endl 
			 << "Publication returned" << endl;
		m_changed = true;
	}
	//Methods with confirmation
	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}
	void LibApp::removePublication() {
		cout << "Publication checked out" << endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}
	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}		
	}
	//Constructor
	LibApp::LibApp() : m_mainMenu("Seneca Library Application"),
					  m_exitMenu("Changes have been made to the data, what would you like to do ?") {
		m_changed = false;
		m_mainMenu << "Add New Publication"
				   << "Remove Publication"
			       << "Checkout publication from library"
			       << "Return publication to library";
		m_exitMenu << "Save changes and exit"
				   << "Cancel and go back to the main menu";
		load();
	}

	void LibApp::run() {
		int select{};
		bool exit{};
		do {
			select = ~m_mainMenu;
			if (!select) {
				if (m_changed) {
					select = ~m_exitMenu;
					if (select != 2) {
						if (select == 1) {
							save();
						}
						else {
							confirm("This will discard all the changes are you sure?") 
							? exit = true : exit = false;
						}
						exit = true;
					}
					else {
						cout << endl;
						exit = false;
					}
				}
				else {
					exit = true;
				}
			}
			else {
				exit = false;
				if (select == 1) {
					newPublication();
					cout << endl;
				}
				else if (select == 2) {
					removePublication();
					cout << endl;
				}
				else if (select == 3) {
					checkOutPub();
					cout << endl;
				}
				else if (select == 4) {
					returnPub();
					cout << endl;
				}
			}
		} while (!exit);
		cout << endl << "-------------------------------------------" << endl 
					 << "Thanks for using Seneca Library Application" << endl;
	}
}