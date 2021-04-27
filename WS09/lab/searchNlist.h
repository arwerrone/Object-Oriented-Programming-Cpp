/**
 * Name:			Angelo Dikon Wong
 * Student ID:			148021199
 * Seneca email:		adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include "Collection.h"
#include <iostream>
using namespace std;
namespace sdds {
	
	//For this template function work, we have to create two typename,
	//one is used to the array that we are reading the values,
	//the other one is the key, the value that we are using to compare.
	//We use different typename, because it may vary.
	//On the first parameter we add the Collection template because it will
	//be responsible for storing the data.
	template<typename T, typename T2>
	bool search(Collection<T>& OMG, const T* arra, int numb, T2 key) {
		bool ok = false;
		for (int i = 0; i < numb; i++) {
			if (arra[i] == key) {
				OMG.add(arra[i]);
				ok = true;
			}
		}
		return ok;
	}

	//For this template function, the inclusion of only one typename is enought,
	//this typename is used as the array that we are going to print.
	//comparing to the past template that we created, this does not require another
	//template as a parameter, the reason is that this functon will only print.
	template<typename T>
	void listArrayElements(const char* tit, const T arra, int numb) {
		cout << tit << endl;
		for (int i = 0; i < numb; i++) {
			cout << i+1 << ": ";
			cout << arra[i] << endl;
		}
	}

}

#endif