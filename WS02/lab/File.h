/*
Workshop 02 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 26, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

	//Open data file
   bool openFile(const char filename[]);

   //Get number of records read from a file
   void closeFile();

   //Close opened file
   int noOfRecords();

   //Read student name data from a file
   bool read(char* studentName);

   //Read student number data from a file
   bool read(int& studentNumber);

   //Read student grade data from a file
   bool read(char& studentGrade);
  
}
#endif // !SDDS_FILE_H_
