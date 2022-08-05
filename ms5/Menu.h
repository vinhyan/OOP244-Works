/* Final Project Milestone 2
Fullname  : Vinh Nhan
Student ID: 171452212
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include <iostream>

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem {
		char* m_content{};
		friend class Menu;
		MenuItem();
		MenuItem(const char* content);
		~MenuItem();
		MenuItem& setMenuItem(const char* content);
		bool isEmpty()const;
		operator bool() const;
		operator const char* ()const;
		std::ostream& displayMenuItem(std::ostream& os) const;
		MenuItem& operator=(const MenuItem& menuItem);
	};

	class Menu {
		MenuItem m_menuTitle{};
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{};
		unsigned int m_numOfItem{};
	public:
		Menu();
		Menu(const char* title);
		~Menu();
		std::ostream& displayTitle(std::ostream& os)const;
		std::ostream& displayMenu(std::ostream& os = std::cout)const;
		unsigned int run() const;
		unsigned int operator~()const;
		Menu& operator<<(const char* menuItemContent);
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](int index)const;

	};

	std::ostream& operator<<(std::ostream& left, const Menu& menu);

}


#endif // !SDDS_MENU_H


