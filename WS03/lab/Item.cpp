#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	void Item::setEmpty() {
		m_itemName[0] = '\0';
		m_price = 0;
		m_taxed = true;
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (price > 0 && name != nullptr) {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		else {
			setEmpty();
		}
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		const double c_tax = 0.13;
		double tax = 0;
		if (m_taxed == true) {
			tax = price() * c_tax;
		}
		else {
			tax = 0;
		}
		return tax;
	}

	bool Item::isValid()const {
		return m_itemName[0] != '\0';
	}

	void Item::display()const {

		if (Item::isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_itemName;
			cout << " | ";
			cout.fill(' ');
			cout.setf(ios::right);
			cout.width(7);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << m_price;
			cout << " | ";
			cout.unsetf(ios::fixed);
			cout.unsetf(ios::right);
			if (m_taxed == true) {
				cout << "Yes";
			}
			else {
				cout << "No ";
			}
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}
