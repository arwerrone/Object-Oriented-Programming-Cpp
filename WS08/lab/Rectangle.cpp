#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds {

	Rectangle::Rectangle() :LblShape() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* value, int wid, int hei) : LblShape(value) {
		m_width = wid;
		m_height = hei;
		int lenLab = (strlen(label()) + 2);
		if (m_height < 3 || m_width < lenLab) {
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& value) {
		LblShape::getSpecs(value);
		value >> m_width;
		value.ignore();			
		value >> m_height;
		value.ignore(1000, '\n');
	}

	void Rectangle::draw(std::ostream& os) const{
		if (m_width != 0) {
			os << "+" << setfill('-') << setw(m_width - 1) << "+" << endl;
			os << "|" << setfill(' ') << setw(m_width - 2) << std::left << label() << "|" << endl;
			int nextLines = m_height - 3;
			for (int i = 0; i < nextLines; i++) {
				os << "|" << setfill(' ') << setw(m_width - 1) <<right << "|" << endl;
			}
			os << "+" << setfill('-') << setw(m_width - 1) << "+";
		}
	}

}
