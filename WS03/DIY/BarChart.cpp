/*
Workshop 03 - Part 2
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : June 5, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "BarChart.h"
#include "Bar.h"

using namespace std;

namespace sdds {
    bool BarChart::validate()const {
        bool allBarsValid = true;
        for (int i = 0; i < m_numOfBars && allBarsValid; i++) {
            if (!(m_bars[i].isValid())) { 
                allBarsValid = false;
            }
        }

        return allBarsValid && (m_numOfBars == m_numOfAddedVal);
    }

    void BarChart::init(const char* title, int noOfSamples, char fill) {
        m_title = new char[strlen(title) + 1]; /*DELETE DMA*/
        strcpy(m_title, title);
        m_numOfBars = noOfSamples;
        m_bars = new Bar[noOfSamples]; /*DELETE DMA*/
        m_fillChar = fill;

        
    }

    void BarChart::add(const char* bar_title, int value) {
        if (m_numOfAddedVal <= m_numOfBars) {
            m_bars[m_numOfAddedVal].set(bar_title, m_fillChar, value);
            m_numOfAddedVal++;
        }
       
    }

    void BarChart::draw()const {
        if (validate()) {
            cout << m_title << endl;
            printDashLine(71);

            for (int i = 0; i < m_numOfBars; i++) {
                m_bars[i].draw();
            }
            printDashLine(71);
        }
        else {
            cout << "Invalid Chart!" << endl;
        }
    }

    void BarChart::deallocate() {
        delete[] m_title;
        delete[] m_bars;
    }

    void printDashLine(int numOfDash) {
        for (int i = 0; i < numOfDash; i++) {
            cout << "-";
        }
        cout << endl;
    }
}