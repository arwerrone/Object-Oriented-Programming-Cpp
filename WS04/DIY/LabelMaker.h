/**
 * Name:			Angelo Dikon Wong
 * Student ID:		148021199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"
namespace sdds {
	class LabelMaker {
		Label* m_labels;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};

}
#endif