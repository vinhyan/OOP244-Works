/*
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : May 18, 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "ShoppingRec.h"

#ifndef sdds_File_H 
#define sdds_File_H

namespace sdds {

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}


#endif
