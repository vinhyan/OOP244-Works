/*
Workshop 02 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 26, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Student.h"
#include "File.h"

using namespace std;


namespace sdds {

    Student* students;
    int noOfStudents;

    //Sort students by grade
    void sort() {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].m_grade > students[j + 1].m_grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    //Store student data in students[]
    bool load(Student& student) {
        char name[128 + 1];
        bool success = false;

        if (read(name) && read(student.m_studentNumber) && read(student.m_grade)) {
            student.m_name = new char[strlen(name) + 1];
            strcpy(student.m_name, name);
            success = true;
        };

        return success;
    }

    //Load student data from a file
    bool load(const char* filename) {
        int i;
        bool success = true;
        openFile(filename);

        noOfStudents = noOfRecords();

        students = new Student[noOfStudents];

        for (i = 0; i < noOfStudents; i++) {
            load(students[i]);
        }

        if (i != noOfStudents) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            success = false;
        }
       
        return success;

    }

    //Display sorted student data
    void display() {

        sort();

        for (int i = 0; i < noOfStudents; i++) {
            cout << i + 1 << ": " << students[i].m_name << ", " << students[i].m_studentNumber 
                 << ": " << students[i].m_grade << endl;
        }
    }

    //Delete dynamic memory
    void deallocateMemory() {
        for (int i = 0; i < noOfStudents; i++) {
            delete[] students[i].m_name;
        }

        delete[] students;
    }






}
