#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TriagePatient.h"
#include <cstring>
#include <string>

using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   void TriagePatient::exterminate() {
	   delete[] symp;
	   symp = nullptr;
   }

   void TriagePatient::angelo(std::istream& istr) {
	   string something;
	   getline(istr, something, '\n');
	   symp = new char[strlen(something.c_str()) + 1];
	   strcpy(symp, something.c_str());
   }

   TriagePatient::TriagePatient():Patient(nextTriageTicket) {
	   symp = nullptr;
	   nextTriageTicket += 1;
   }

   char TriagePatient::type() const {
	   char ret = 'T';
	   return ret;
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const {
	   Patient::csvWrite(ostr);
	   ostr << "," << symp;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr) {
	   exterminate();
	   Patient::csvRead(istr);
	   istr.ignore(1000,',');
	   angelo(istr);
	   nextTriageTicket = Patient::number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr)const {
	   if (Patient::fileIO())
		   csvWrite(ostr);
	   else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl << "Symptoms: ";
		   ostr << symp << endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr) {
	   if (Patient::fileIO())
		   csvRead(istr);
	   else {
		   exterminate();
		   Patient::read(istr);
		   cout << "Symptoms: ";
		   angelo(istr);
	   }
	   return istr;
   }

   TriagePatient::~TriagePatient() {
	   exterminate();
   }

}
