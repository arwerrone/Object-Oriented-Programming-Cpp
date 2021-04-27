#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include "Collection.h"
#include <iostream>
using namespace std;
namespace sdds {
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
