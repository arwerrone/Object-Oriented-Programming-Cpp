/**
 * Name:			Angelo Dikon Wong
 * Student ID:			148021199
 * Seneca email:		adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/

#ifndef SDDS_SHAPE_H__
#define SDDS_SHAPE_H__
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream&)const = 0;
		virtual void getSpecs(std::istream&) = 0;		//caso n seja pure virtual usar dbaixo
		//void getSpecs(std::istream&);
		virtual ~Shape() {};
	};
	std::istream& operator>>(std::istream& in, Shape& righOper);
	std::ostream& operator<<(std::ostream& os, const Shape& rightOper);
}
#endif
