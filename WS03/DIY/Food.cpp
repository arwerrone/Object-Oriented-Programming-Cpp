/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {

	void Food::setName(const char* name) {
		strnCpy(f_name, name, 30);
		f_name[30] = '\0';
	}

	void Food::setEmpty() {
		f_name[0] = '\0';
		m_calories = 0;
		m_time = 0;
	}

	void Food::set(const char* name, int calories, int time) {
		if (time > 0 && name != nullptr) {
			setName(name);
			m_calories = calories;
			m_time = time;
		}
		else {
			setEmpty();
		}
	}

	int Food::calories()const {
		return m_calories;
	}

	/*double Food::tax()const {
		const double c_tax = 0.13;
		double tax = 0;
		if (m_taxed == true) {
			tax = price() * c_tax;
		}
		else {
			tax = 0;
		}
		return tax;
	}*/

	bool Food::isValid()const {
		return f_name[0] != '\0';
	}

	void Food::display()const {

		if (Food::isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(30);
			cout.fill('.');
			cout << f_name;
			cout << " | ";
			//////////////////////

			cout.fill(' ');
			cout.setf(ios::right);
			cout.width(4);
			//cout.precision(2);

			//cout.setf(ios::fixed);

			cout << m_calories;
			cout << " | ";
			//cout.unsetf(ios::fixed);
			cout.unsetf(ios::right);

			cout.width(10);
			switch (m_time)
			{
			case 1:
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner";
				break;
			case 4:
				cout << "Snack";
				break;
			default:
				break;
			}
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}