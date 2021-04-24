/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

	void CalorieList::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool CalorieList::isValid()const {
		bool valid = m_items != nullptr;//&& m_title[0] != '\0';

		for (int i = 0; valid && i < m_noOfFoods; i++) {
			valid = m_items[i].isValid();
		}
		return valid;
	}

	/*double CalorieList::totalTax()const {
		double tax = 0;
		for (int i = 0; i < m_noOfFoods; i++)
		{
			tax += m_items[i].tax();
		}
		return tax;
	}*/

	int CalorieList::totalCalories()const {
		int cal = 0;
		for (int i = 0; i < m_noOfFoods; i++)
		{
			cal += m_items[i].calories();
		}
		return cal;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			/*cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;*/
			cout << "|  Daily Calorie Consumption                         |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "| Food name                      | Cals | When       |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "| Food name                      | Cals | When       |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
		}
	}

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "|    Total Calories for today: ";
			cout.width(8);
			//cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << totalCalories();
			cout << " |";
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			cout.width(13);
			cout.setf(ios::right);
			cout << " |" << endl;
			cout.unsetf(ios::right);

			cout << "+----------------------------------------------------+" << endl;
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
	}

	void CalorieList::init(int noOfItems) {
		if (noOfItems > 0) {
			m_noOfFoods = noOfItems;
			m_itemsAdded = 0;

			m_items = new Food[m_noOfFoods]();
		}
		else {
			setEmpty();
		}
	}

	bool CalorieList::add(const char* item_name, int calories, int when) {
		bool ok = false;

		if (m_itemsAdded < m_noOfFoods) {
			m_items[m_itemsAdded++].set(item_name, calories, when);
			ok = true;
		}
		else{
			ok = false;
		}
		return ok;
	}

	void CalorieList::display()const {
		Title();
		for (int i = 0; i < m_noOfFoods; i++) {
			m_items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		int i;
		for (i = 0; i < m_noOfFoods; i++) {
			m_items[i].setEmpty();
		}
		delete[] m_items;
		m_items = nullptr;
		m_noOfFoods = 0;
		m_itemsAdded = 0;
	}

}