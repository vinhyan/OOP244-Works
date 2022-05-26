/*
Workshop 02 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 26, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

namespace sdds {

	struct Student {
		char* m_name;
		int m_studentNumber;
		char m_grade;
	};

	//Sort students by grade
	void sort();

	//Store student data in students[]
	bool load(Student& student);

	//Load student data from a file
	bool load(const char* filename);

	//Display sorted student data
	void display();

	//Delete dynamic memory
	void deallocateMemory();

}

#endif // !SDDS_STUDENT_H_






