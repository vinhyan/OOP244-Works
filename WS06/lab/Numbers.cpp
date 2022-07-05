/*
Workshop 06 - Part 1
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 07/05/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::Numbers(const Numbers& numbers) {
       setEmpty();
       m_isOriginal = false;
       operator=(numbers);
   }
   Numbers& Numbers::operator=(const Numbers& numbers) {
       if (this != &numbers) {
           delete[] m_numbers;
           m_numCount = numbers.m_numCount;
           m_numbers = new double[m_numCount];
           for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = numbers.m_numbers[i];
           }
       }
       return *this;
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   int Numbers::numberCount() {
       int count{};
       ifstream f(m_filename);
       if (f.is_open()) {
           while (f) {
               count += (f.get() == '\n');
           }
       }
       return count;
   }
   bool Numbers::load() {
       int i = 0;
       
       if (m_numCount > 0) {
           delete[] m_numbers;
           m_numbers = new double[m_numCount];
           ifstream f(m_filename);
           if (f.is_open()) {
               while (f) {
                   f >> m_numbers[i];
                   if (f) i++;
               }
           }
       }
       return (i == m_numCount);
   }
   void Numbers::save() {
       if (m_isOriginal && !isEmpty()) {
           ofstream f(m_filename);
           if (f.is_open()) {
               for (int i = 0; i < m_numCount; i++) {
                   f << m_numbers[i] << endl;
               }
           }
       }
   }
   Numbers& Numbers::operator+=(const double number) {
       double* temp{};
       if (!isEmpty()) {
           temp = new double[m_numCount + 1];
           for (int i = 0; i < m_numCount; i++) {
               temp[i] = m_numbers[i];
           }
           temp[m_numCount] = number;
           m_numCount++;
           delete[] m_numbers;
           m_numbers = temp;
           sort();
       }
       return *this;
   }
   std::ostream& Numbers::display(std::ostream& ostr) const {
       if (isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }

           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i];
               if (i != m_numCount - 1) {
                   ostr << ", ";
               }
               else {
                   ostr << endl;
               }
           }
           ostr << "-------------------------" << endl 
                << "Total of " << m_numCount << " number(s)" << endl
                << "Largest number:  " << max() << endl
                << "Smallest number: " << min() << endl
                << "Average :        " << average() << endl;
           ostr << "=========================";
       }
       return ostr;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   std::ostream& operator<<(std::ostream& os, const Numbers& N) {
       return N.display(os);
   }

   std::istream& operator>>(std::istream& is, Numbers& N){
       double number{};
       is >> number;
       if (is.fail()) {
           is.clear();
           is.ignore(1000, '\n');
       }
       else {
           N += number;
       }
       return is;
   }
}
