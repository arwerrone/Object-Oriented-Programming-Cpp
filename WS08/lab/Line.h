/**
 * Name:			Angelo Dikon Wong
 * Student ID:			148021199
 * Seneca email:		adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/

#ifndef SDDS_LINE_H__
#define SDDS_LINE_H__
#include <iostream>
#include "LblShape.h"
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char*, int);
		void getSpecs(std::istream&);
		void draw(std::ostream&) const;
	};

}
#endif