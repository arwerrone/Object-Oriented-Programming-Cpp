#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include "Truck.h"
#include "cstring.h"
#include <iostream>

using namespace std;
namespace sdds {
	
	Truck::Truck(const char* plate, int year, double capacity, const char* address)
		:MotorVehicle(plate, year), m_capacity(capacity){
		m_cargo = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		bool ok = false;
		double oldcargo = m_cargo;
		if (cargo <= m_capacity) {
			m_cargo += cargo;
			ok = true;
		}
		if ((m_cargo + cargo) > m_capacity) {
			m_cargo = m_capacity;
		}
		if (oldcargo == m_capacity) {
			ok = false;
		}
		return ok;
	}

	bool Truck::unloadCargo() {	
		bool unload = this->m_cargo > 0;
		if (unload) {						
			m_cargo = 0;
		}
		return unload;						
	}

	std::ostream& Truck::write(std::ostream& os) const {
		MotorVehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;
		return in;
	}

	std::istream& operator>>(std::istream& in, Truck& righOper) {
		return righOper.read(in);
	}

	std::ostream& operator<<(std::ostream& os, const Truck& rightOper) {
		return rightOper.write(os);
	}

}
