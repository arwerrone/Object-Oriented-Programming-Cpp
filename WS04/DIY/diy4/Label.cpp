/**
 * Name:			Angelo Dikon Wong
 * Student ID:		148021199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/

#include <iostream>
#include "Label.h"
#include "cstring.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds {

	void Label::setToDefault() {
		strCpy(m_frame, "+-+|+-+|");
		m_conent = nullptr;
	}

	Label::Label() {
		setToDefault();
	}

	Label::Label(const char* frameArg) {
			strCpy(m_frame, frameArg);
			m_conent = nullptr;
	}


	Label::Label(const char* frameArg, const char* content) {
		int i = strLen(frameArg);
		int j = strLen(content);
		if (i == 8) {
			strCpy(m_frame, frameArg);
			m_conent = nullptr;
		}

		if (j < 70) {
			delete[] m_conent;
			m_conent = new char[j + 1];
			strCpy(m_conent, content);
		}
		else;
	}

	Label::~Label() {
		delete[] m_conent;
		m_conent = nullptr;
	}
	
	void Label::readLabel() {
		char temp[71];
		cin.getline(temp, 71);
		if (cin.fail()) cin.ignore(1000, '\0');
		m_conent = new char[strLen(temp) + 1];
		strCpy(m_conent, temp);
	}

	std::ostream& Label::printLabel()const {
		//int len = sizeof(m_conent);
		int len = 0;
		if (m_conent != nullptr) {

			len += strLen(m_conent);

			cout << m_frame[0];
			for (int i = 0; i < len + 2; i++, cout << m_frame[1]);
			cout << m_frame[2] << endl;

			cout << m_frame[7];
			cout.width(len + 3);
			cout << m_frame[3] << endl;

			cout << m_frame[7];
			cout << " ";
			cout << m_conent;
			cout << " ";

			cout << m_frame[3] << endl;
			cout << m_frame[7];
			cout.width(len + 3);
			cout << m_frame[3] << endl;
			cout << m_frame[6];
			for (int i = 0; i < len + 2; i++, cout << m_frame[5]);
			cout << m_frame[4];
		}

		return cout;
	}

}