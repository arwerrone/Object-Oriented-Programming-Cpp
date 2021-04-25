/**
 * Name:			Angelo Dikon Wong
 * Student ID:			148021199
 * Seneca email:		adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/

#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__
#include <iostream>
#include "Shape.h"
namespace sdds {
	class LblShape : public Shape {
		char* m_label = nullptr;
		void setLabel(const char*);
	protected:
		const char* label()const;
	public:
		LblShape(){};
		LblShape(const char*);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream&);
	};
}

#endif