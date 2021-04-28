/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Patient.h"
#include "IOAble.h"
#include <cstring>
#include "utils.h"

using namespace std;
namespace sdds {

	Patient::Patient(int tickNum,bool fileioflag):m_ticket(tickNum){
		m_fileIO = fileioflag;
	}

	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::fileIO()const {
		return m_fileIO;
	}

	void Patient::fileIO(bool value) {
		m_fileIO = value;
	}

	bool Patient::operator==(char single) const{
		bool ok = false;
		if (single == type()) {
			ok = true;
		}
		return ok;
	}

	bool Patient::operator==(const Patient& patien) const {
		bool ok = false;
		if (type() == patien.type()) {
			ok = true;
		}
		return ok;
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Patient::operator Time() const {
		return Time(m_ticket);
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr)const {
		ostr << type() << ",";
		ostr << m_name << ",";
		ostr << m_OHIPnum << ",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}

	//My implemented function
	void Patient::setName(const char* value) {
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[strlen(value) + 1];
		strcpy(m_name, value);
	}

	std::istream& Patient::csvRead(std::istream& istr) {
		char thename[100];
		int thenumber = 0;
		istr.getline(thename,99,',');
		setName(thename);
		//m_OHIPnum = getInt(100000000,999999999);
		//Hello prof, I tried to use the getint utils, but it kept reading the comma,
		//so I changed it in the way that it works, if this is not acceptable, please tell me
		istr >> thenumber;
		if (thenumber >= 100000000 && thenumber <= 999999999) {
			m_OHIPnum = thenumber;
		}
		istr.ignore();
		m_ticket.csvRead(istr);
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr)const {
		m_ticket.write(ostr);
		ostr << endl;
		for (int i = 0; m_name[i] && i < 25; i++) {
			ostr << m_name[i];
		}
		ostr << ", OHIP: " << m_OHIPnum;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr) {
		cout << "Name: ";
		char thename[100];
		istr.getline(thename, 99, '\n');
		setName(thename);
		cout << "OHIP: ";
		m_OHIPnum = getInt(100000000 ,999999999,"","Invalid OHIP Number, ");

		return istr;
	}

}