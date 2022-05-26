/*
Workshop 02 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 26, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Student.h"


namespace sdds {
   FILE* fptr;

   //Open data file
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   //Get number of records read from a file
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   //Close opened file
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   //Read student name data from a file
   bool read(char* studentName) {
       bool success = fscanf(fptr, "%[^,],", studentName) == 1;
       return success;
   }

   //Read student number data from a file
   bool read(int& studentNumber) {
       bool success = fscanf(fptr, "%d,", &studentNumber) == 1;
       return success;
   }

   //Read student grade data from a file
   bool read(char& studentGrade) {
       bool success = fscanf(fptr, "%c\n", &studentGrade) == 1;
       return success;
   }

  
}