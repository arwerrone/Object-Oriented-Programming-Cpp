#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include "cstring.h"
#include <iostream>

using namespace std;
namespace sdds {

	MotorVehicle::MotorVehicle(const char* licenseplate, int year) {
		strCpy(m_currentAddress, "Factory");
		strCpy(m_licensePlate, licenseplate);
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(m_currentAddress, address)) {
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_licensePlate << "| |";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_currentAddress << " ---> ";
			cout.unsetf(ios::right);
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout << "|" << endl;

			strCpy(m_currentAddress, address);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const{
		os << "| " << m_year << " | ";
		os << m_licensePlate << " | ";
		os << m_currentAddress;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in){
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_licensePlate;
		cout << "Current location: ";
		in >> m_currentAddress;
		return in;
	}
	
	std::istream& operator>>(std::istream& in, MotorVehicle& righOper) {
		return righOper.read(in);
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& rightOper) {
		return rightOper.write(os);
	}

}
