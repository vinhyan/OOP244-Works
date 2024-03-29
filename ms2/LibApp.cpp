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
		cout << "Returning publication" << endl 
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
		cout << "Removing publication from library" << endl;
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
					  m_exitMenu("Changes have been made to the data, what would you like to do?") {
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
			//Display MAIN menu and let user select menu option
			select = ~m_mainMenu;  
			if (!select) {            //select (0) exit MAIN menu
				if (m_changed) { 
					//Display EXIT menu and let user select menu option
					select = ~m_exitMenu; 
					switch (select) {
					case 1:
						save();
						exit = true;
						break;
					case 2:
						cout << endl;
						exit = false;
						break;
					default:
						confirm("This will discard all the changes are you sure?") ? 
						exit = true : exit = false;
					}
				}
				else {
					exit = true;
				}
			}
			else {      //select (1 - 4) options MAIN menu
				exit = false;
				switch (select) {
				case 1:
					newPublication();
					cout << endl;
					break;
				case 2:
					removePublication();
					cout << endl;
					break;
				case 3:
					checkOutPub();
					cout << endl;
					break;
				default:
					returnPub();
					cout << endl;
				}
			}
		} while (!exit);
		cout << endl << "-------------------------------------------" << endl 
					 << "Thanks for using Seneca Library Application" << endl;
	}
}