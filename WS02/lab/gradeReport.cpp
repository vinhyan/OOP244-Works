/* ------------------------------------------------------
Workshop 2 part 1
Module: N/A
Filename: gradeReport.cpp 
  in submission this file will be replaced with main_prof.cpp
  that loads "simpsons.csv" instead
Version 1
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/

/*
Workshop 02 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 26, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Student.h"
using namespace sdds;
int main() {
   if (load("students.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}