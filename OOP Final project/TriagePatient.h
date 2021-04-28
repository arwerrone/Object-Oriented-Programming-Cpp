/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds {
	class TriagePatient : public Patient {
		char* symp;
	public:
		TriagePatient();
		char type() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		~TriagePatient();
		//my implemented fucntion
		void exterminate();	//this function will delete the dynamic memory. Reference to doctor who
		void angelo(std::istream& istr); //this function will dynamically alocate cstring to symp. No creative name this time
	};

}
#endif // !SDDS_TRIAGEPATIENT_H


