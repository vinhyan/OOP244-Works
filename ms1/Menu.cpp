/* Final Project Milestone 1
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	//MenuItem
	MenuItem::MenuItem() {
		m_content = nullptr;
	}
	MenuItem::MenuItem(const char* content) {
		setMenuItem(content);
	}
	MenuItem::~MenuItem() {
		delete[] m_content;
	}
	MenuItem& MenuItem::setMenuItem(const char* content) {
		if (content && content[0] != '\0') {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
		else {
			m_content = nullptr;
		}
		return *this;
	}
	bool MenuItem::isEmpty()const {
		return !(m_content && m_content[0] != '\n');
	}
	MenuItem::operator bool() const {
		return !isEmpty();
	}
	MenuItem::operator const char* () const {
		return m_content;
	}
	std::ostream& MenuItem::displayMenuItem(std::ostream& os)const {
		if (!isEmpty()) {
			os << m_content;
		}
		return os;
	}

	MenuItem& MenuItem::operator=(const MenuItem& menuItem) {
		return setMenuItem((const char*)menuItem);
	}

	//Menu 
	Menu::Menu() {
		m_menuTitle.m_content = nullptr;
	}
	Menu::Menu(const char* title) {
		if (title && title[0] != '\n') {
			m_menuTitle.setMenuItem(title);
		}
	}
	Menu::~Menu() {
		for (unsigned int i = 0; i < m_numOfItem; i++) {
			delete m_menuItems[i];
		}
	}
	std::ostream& Menu::displayTitle(std::ostream& os)const {
		if (m_menuTitle.m_content && m_menuTitle.m_content[0] != '\n') {
			os << (const char*)m_menuTitle;
		}
		return os;
	}
	std::ostream& Menu::displayMenu(std::ostream& os = cout)const {
		if (m_menuTitle.m_content && m_menuTitle.m_content[0] != '\n')
			displayTitle(os) << endl;
		for (unsigned int i = 0; i < m_numOfItem; i++) {
			os.width(2);
			os.setf(ios::right);
			os << i + 1 << "- ";
			m_menuItems[i]->displayMenuItem(os) << endl;
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}
	unsigned int Menu::run()const {
		displayMenu();
		return selectOption(0, m_numOfItem);
	}
	unsigned int Menu::operator~() const{
		return run();
	}
	Menu& Menu::operator<<(const char* menuitemConent) {
		if (m_numOfItem != MAX_MENU_ITEMS) {
			m_menuItems[m_numOfItem] = new MenuItem;
			m_menuItems[m_numOfItem]->setMenuItem(menuitemConent);
			m_numOfItem++;
		}
		return *this;
	}
	Menu::operator int() const {
		return m_numOfItem;
	}
	Menu::operator unsigned int() const {
		return m_numOfItem;
	}
	Menu::operator bool() const {
		return m_numOfItem > 0;
	}
	const char* Menu::operator[](int index) const {
		return (const char*)*m_menuItems[index % m_numOfItem];
	}
	std::ostream& operator<<(std::ostream& left, Menu& menu) {
		return menu.displayTitle(left);
	}

}