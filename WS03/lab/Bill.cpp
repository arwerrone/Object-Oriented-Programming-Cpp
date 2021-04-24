/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const {
		bool valid = m_items != nullptr && m_title[0] != '\0';

			for (int i = 0; valid && i < m_noOfItems; i++) {
				valid = m_items[i].isValid();
			}
		return valid;
	}

	double Bill::totalTax()const {
		double tax = 0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			tax += m_items[i].tax();
		}
		return tax;
	}

	double Bill::totalPrice()const {
		double price = 0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			price += m_items[i].price();
		}
		return price;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
			cout << "| Item Name            | Price   + Tax |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
			cout << "| Item Name            | Price   + Tax |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
		}
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << totalTax();
			cout << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			////////////////////////////////
			cout << "|              Total Price: ";
			cout.width(10);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << totalPrice();
			cout << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			////////////////////////////////
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << totalTax() + totalPrice();
			cout << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			/// ///////////
			cout << "+--------------------------------------+" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
			cout << "+--------------------------------------+" << endl;
		}
	}
	///////////////////////PUBLIC::::://////////////

	void Bill::init(const char* title, int noOfItems) {
		if (title != nullptr && noOfItems > 0) {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);

			m_items = new Item[m_noOfItems]();
		}
		else {
			setEmpty();
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool ok = false;
	
		if (m_itemsAdded <= m_noOfItems) {
			m_items[m_itemsAdded++].set(item_name, price, taxed);
			ok = true;
		}
		else {
			ok = false;
		}
		return ok;
	}

	void Bill::display()const {
		Title();
		for (int i = 0; i < m_noOfItems ; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate() {
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].setEmpty();
		}
		delete[] m_items;
		m_items = nullptr;
		m_noOfItems = 0;
		m_itemsAdded = 0;
	}

}