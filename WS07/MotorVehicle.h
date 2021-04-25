/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>

namespace sdds {
	class MotorVehicle {
		char m_licensePlate[9];
		char m_currentAddress[64];
		int m_year;
	public:
		MotorVehicle(const char* licenseplate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::istream& operator>>(std::istream& in, MotorVehicle& righOper);
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& rightOper);
}

#endif