/**
 * Name: Angelo Dikon Wong
 * Student ID:148021199
 * Seneca email: adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/
#ifndef NAMESPACE_FILE_H // replace with relevant names
#define NAMESPACE_FILE_H
#include "ShoppingRec.h"

// Your header file content goes here
namespace sdds {

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);

}
#endif