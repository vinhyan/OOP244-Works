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
