#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#include "Time.h"

namespace sdds {
	class Patient : public IOAble {
		char* m_name = nullptr;
		int m_OHIPnum = 0;
		Ticket m_ticket;
		bool m_fileIO;
	public:
		Patient(int tickNum=0, bool fileioflag = false);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		~Patient();
		virtual char type() const = 0;
		bool fileIO()const;
		void fileIO(bool value);
		bool operator==(char)const;
		bool operator==(const Patient& patien) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		void setName(const char* value);
		
	};
}

#endif
