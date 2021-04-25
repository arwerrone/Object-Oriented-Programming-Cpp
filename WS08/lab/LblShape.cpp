#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LblShape.h"
#include <cstring>

using namespace std;
namespace sdds {

	const char* LblShape::label()const {
		return m_label;
	}

	void LblShape::setLabel(const char* value) {
		delete[] m_label;
		m_label = nullptr;
		m_label = new char[strlen(value) + 1];
		strcpy(m_label, value);
	}

	LblShape::LblShape(const char* value) {
		setLabel(value);
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& value) {
		char something[100];
		value.getline(something, 99, ',');
		setLabel(something);
	}

}
