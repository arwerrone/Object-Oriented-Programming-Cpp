/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"

namespace sdds {
	class Truck : public MotorVehicle{
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* plate, int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::istream& operator>>(std::istream& in, Truck& righOper);
	std::ostream& operator<<(std::ostream& os, const Truck& rightOper);
}

#endif