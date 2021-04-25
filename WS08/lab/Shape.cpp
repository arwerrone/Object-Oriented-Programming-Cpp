#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {

	std::istream& operator>>(std::istream& in, Shape& righOper) {
		righOper.getSpecs(in);
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Shape& rightOper) {
		rightOper.draw(os);
		return os;
	}
}
