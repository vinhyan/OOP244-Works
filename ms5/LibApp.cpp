/* Final Project Milestone 5
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
#include "Utils.h"
#include "Date.h"

using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message) {
		Menu confirm(message);
		confirm << "Yes";
		return !!(~confirm);
	}
	void LibApp::load() {
		char type{};
		cout << "Loading Data" << endl;
		ifstream infile;
		infile.open(m_filename);
		for (int i = 0; infile; i++) {
			infile >> type;
			infile.ignore();
			if (infile) {
				if (type == 'B') {
					m_pubs[i] = new Book;
				}
				else if (type == 'P') {
					m_pubs[i] = new Publication;
				}
				if (m_pubs[i]) {
					infile >> *m_pubs[i];
					m_numOfPub++;
				}   
			}
		}
		m_lastRefNum = m_pubs[m_numOfPub - 1]->getRef();
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream outfile(m_filename);
		for (int i = 0; i < m_numOfPub; i++) {
			if (m_pubs[i]->getRef() != 0) {
				outfile << *m_pubs[i] << endl;
			}
		}
	}
	int LibApp::search(int searchMode) {  //searchMore "2": onLoan() is TRUE; "3": onLoan() is FALSE; "1": search all
		int select{};
		char title[256]{};
		PublicationSelector ps("Select one of the following found matches:");
		int matches = 0;
		int ref{};
		//cout << "Searching for publication" << endl;

		select = ~m_pubMenu;
		cout << "Publication Title: ";
		cin.getline(title, 256);
		
		if (select) {
			for (int i = 0; i < m_numOfPub; i++) {
				if (m_pubs[i]->getRef() != 0) {   //Filter out deleted publications
					if (select == 1) {  //select 'Book'
						if (m_pubs[i]->type() == 'B') { 
							if (strstr(*m_pubs[i], title)) {
								if (searchMode == 2) {
									if (m_pubs[i]->onLoan()) {
										ps << m_pubs[i];
										matches++;
									}
								}
								else if (searchMode == 3) {
									if (!m_pubs[i]->onLoan()) {
										ps << m_pubs[i];
										matches++;
									}
								}
								else {
									ps << m_pubs[i];
									matches++;
								}
							}
						}
					}
					else if (select == 2) {  //select 'Publication'
						if (m_pubs[i]->type() == 'P') {
							if (strstr(*m_pubs[i], title)) {
								if (searchMode == 2) {
									if (m_pubs[i]->onLoan()) {
										ps << m_pubs[i];
										matches++;
									}
								}
								else if (searchMode == 3) {
									if (!m_pubs[i]->onLoan()) {
										ps << m_pubs[i];
										matches++;
									}
								}
								else {
									ps << m_pubs[i];
									matches++;
								}
							}
						}
					}
				}
			}
			if (matches) {
				ps.sort();
				ref = ps.run();
				if (!ref) select = 0;
			}
			else {
				cout << "No matches found!" << endl;
			}
		}
		if (!select) {
			cout << "Aborted!" << endl;

		}
		return ref;
	}
	void LibApp::returnPub() {
		int ref{};
		int index{};
		int loanDays{};
		double penaltyFee{};
		Date today;
		cout << "Return publication to the library" << endl;
		ref = search(2);
		if (ref) {
			for (int i = 0; i < m_numOfPub; i++) {
				if (m_pubs[i]->getRef() == ref) {
					index = i;
					i = m_numOfPub;
				}
			}
			cout << *m_pubs[index] << endl;
			if (confirm("Return Publication?")) {
				loanDays = today - m_pubs[index]->checkoutDate();
				if (loanDays > 15) {
					penaltyFee = (loanDays - 15) * 0.50;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penaltyFee << " penalty for being "
						<< (loanDays - 15) << " days late!" << endl;
				}
				m_pubs[index]->set(0);
				cout << "Publication returned" << endl;
				m_changed = true;
			}
		}
	}
	//Methods with confirmation
	void LibApp::newPublication() {
		int select{};
		Publication* pub{};
		if (m_numOfPub == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;
			select = ~m_pubMenu;
			if (select == 1) {
				pub = new Book;
			}
			else if (select == 2) {
				pub = new Publication;
			}

			if (select) {
				cin >> *pub;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!";
				}
				else {
					if (confirm("Add this publication to the library?")) {
						if (pub) {
							m_lastRefNum++;
							pub->setRef(m_lastRefNum);
							m_pubs[m_numOfPub] = pub;
							m_numOfPub++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else {
							cout << "Failed to add publication!";
							delete pub;
						}
					}
					else {
						select = 0;
					}
				}
			}
			if (!select) cout << "Aborted!" << endl;
		}
	}
	void LibApp::removePublication() {
		int ref{};
		int index{};
		cout << "Removing publication from the library" << endl;
		ref = search(1);
		if (ref) {
			for (int i = 0; i < m_numOfPub; i++) {
				if (m_pubs[i]->getRef() == ref) {
					index = i;
					i = m_numOfPub;
				}
			}
			cout << *m_pubs[index] << endl;
			if (confirm("Remove this publication from the library?")) {
				m_pubs[index]->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}
	void LibApp::checkOutPub() {
		int ref{};
		int index{};
		int membership{};
		cout << "Checkout publication from the library" << endl;
		ref = search(3);
		if (ref) {
			for (int i = 0; i < m_numOfPub; i++) {
				if (m_pubs[i]->getRef() == ref) {
					index = i;
				}
			}
			cout << *m_pubs[index] << endl;
			if (confirm("Check out publication?")) {
				cout << "Enter Membership number: ";
				do {
					membership = getInt();
				} while (!(membership > 9999 && membership < 100000) && cout << "Invalid membership number, try again: ");
				m_pubs[index]->set(membership);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
	}
	//Constructor
	LibApp::LibApp(const char* filename) : m_pubMenu("Choose the type of publication:"),
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?") {
		strcpy(m_filename, filename);
		m_numOfPub = 0;
		m_changed = false;
		m_pubMenu  << "Book" 
				   << "Publication";
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

	Publication* LibApp::getPub(int libRef) {
		int index = -1;
		for (int i = 0; i < m_numOfPub && index == -1; i++) {
			if (m_pubs[i]->getRef() == libRef) index = i;
		}
		if (index == -1) index = 0;
		return m_pubs[index];
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_numOfPub; i++) {
			delete m_pubs[i];
		}
	}

}