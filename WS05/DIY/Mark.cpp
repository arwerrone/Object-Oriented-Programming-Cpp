/**
 * Name:                Angelo Dikon Wong
 * Student ID:          148021199
 * Seneca email:        adikon-wong@myseneca.ca
 * Section:             OOP244 - NGG
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {

	void Mark::Validate() {
		if (m_value < 0 || m_value > 100) {
			m_value = -1;
		}
	}

	Mark::Mark() {
		m_value = 0;
	}

	Mark::Mark(int grade) {
		m_value = grade;
		Validate();
	}

	Mark::operator int() const{
		int ret = 0;
		if (m_value != -1) {
			ret = m_value;
		}
		return ret;
	}

	Mark& Mark::operator+=(int plus) {
		if (m_value != -1) {
			m_value += plus;

			Validate();
		}
		return *this;
	}
	///Possivel erro devido a falta de informação 
	/// olhando exemplo o n nao faz sentido
	Mark& Mark::operator=(int i) {
		m_value = i;
		Validate();

		return *this;
	}

	Mark::operator double() const {
		int gpa = 0;
		if (m_value == -1) {
			gpa = 0;
		}
		else if (m_value >= 0 && m_value < 50) {
			gpa = 0;
		}
		else if (m_value >=50 && m_value < 60) {
			gpa = 1;
		}
		else if (m_value >=60 && m_value < 70 ) {
			gpa = 2;
		}
		else if (m_value >=70 && m_value < 80) {
			gpa = 3;
		}
		else if (m_value >=80 && m_value <=100) {
			gpa = 4;
		}

		return gpa;
	}

	Mark::operator char() const {
		char mark = 'X';
		if (m_value == -1) {
			mark = 'X';
		}
		else if (m_value >= 0 && m_value < 50) {
			mark = 'F';
		}
		else if (m_value >= 50 && m_value < 60) {
			mark = 'D';
		}
		else if (m_value >= 60 && m_value < 70) {
			mark = 'C';
		}
		else if (m_value >= 70 && m_value < 80) {
			mark = 'B';
		}
		else if (m_value >= 80 && m_value <= 100) {
			mark = 'A';
		}

		return mark;
	}

	int operator+= (int& val, const Mark& right) {
		return val += int(right);
	}

}