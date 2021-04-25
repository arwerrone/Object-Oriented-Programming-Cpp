#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {

	Line::Line():LblShape() {
		m_length = 0;
	}

	Line::Line(const char* value, int leng):LblShape(value) {
		m_length = leng;
	}

	void Line::getSpecs(std::istream& value) {
		LblShape::getSpecs(value);
		value >> m_length;
		value.ignore(1000, '\n');
	}

	void Line::draw(std::ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			for (int i = 0; i < m_length; i++)
				os << "=";
		}
	}

}
