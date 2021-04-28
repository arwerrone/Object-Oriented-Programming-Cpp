/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include <iostream>
#include "IOAble.h"

using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& os, IOAble& right) {
		return right.write(os);
	}

	std::istream& operator>>(std::istream& in, IOAble& right) {
		return right.read(in);
	}

}