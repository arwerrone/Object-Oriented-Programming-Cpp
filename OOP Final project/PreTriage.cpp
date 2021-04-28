/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PreTriage.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
namespace sdds {

	PreTriage::PreTriage(const char* dataFilename)
		:m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2)
		, m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
		//, m_averCovidWait(15)
		//, m_averTriageWait(5)
	{
		delete[] m_dataFilename;
		m_dataFilename= nullptr;
		m_dataFilename = new char[strlen(dataFilename)+1];
		strcpy(m_dataFilename, dataFilename);
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		load();
	}

	PreTriage::~PreTriage() {
		ofstream tf(m_dataFilename);
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait << endl;
		cout << "   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;
		tf << m_averCovidWait << "," << m_averTriageWait << endl;
		for (int i = 0; i < m_lineupSize; i++) {
			cout << i + 1 << "- ";
			m_lineup[i]->csvWrite(cout);
			cout << endl;
			m_lineup[i]->csvWrite(tf);
			tf << endl;
		}

		for (int i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i] != nullptr) {
			delete m_lineup[i];
			m_lineup[i] = nullptr;
			}
		}
		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		cout << "done!"<<endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p)const {
		int countNum = 0;
		for (int i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == p.type())
				countNum++;
		}
		Time toret;
		if (p.type() =='C')
			toret = m_averCovidWait.operator int() * countNum;
		if (p.type() == 'T')
			toret = int(m_averTriageWait) * countNum;

		return toret;
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time ct;
		ct.setToNow();
		if (p.type() == 'C')
			m_averCovidWait = ((ct - Time(p)) + (m_averCovidWait * ((unsigned)p.number() - 1))) / (unsigned)p.number();
		if (p.type() == 'T')
			m_averTriageWait = ((ct - Time(p)) + (m_averTriageWait * ((unsigned)p.number() - 1))) / (unsigned)p.number();
	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		bool ok = true;
		int toret = -1;
		for (int i = 0; ok && i < m_lineupSize; i++) {
			if (*m_lineup[i] == type) {
				ok = false;
				toret = i;
			}
		}
		return toret;
	}
	
	void PreTriage::load() {

		ifstream fin(m_dataFilename);
		cout << "Loading data..." << endl;
		fin >> m_averCovidWait;
		fin.ignore();
		fin >> m_averTriageWait;
		fin.ignore(100, '\n');

		Patient* p = nullptr;
		char omg = 'x';
		for (int i = 0; i < maxNoOfPatients && fin; i++) {
			omg = 'x';
			fin >> omg;
			fin.ignore();
			p = nullptr;
			if (omg == 'C')
				p = new CovidPatient();
			else if (omg == 'T')
				p = new TriagePatient();
			if (p) {
				p->fileIO(true);
				fin >> *p;
				m_lineup[m_lineupSize++] = p;
			}
		}
		if (fin)
			cout << "Warning: number of records exceeded " << maxNoOfPatients <<endl;
		if (m_lineupSize > 0)
			cout << m_lineupSize << " Records imported..." << endl << endl;
		else
			cout << "No data or bad data file!" << endl << endl;
	}
	
	void PreTriage::reg() {
		bool ok = false;
		int selection;
		if (m_lineupSize == maxNoOfPatients)
			cout << "Line up full!" << endl;
		else {
			m_pMenu >> selection;
			
			if (selection == 1)
				m_lineup[m_lineupSize] = new CovidPatient();
			if (selection == 2)
				m_lineup[m_lineupSize] = new TriagePatient();
			if (selection == 0)
				ok = true;

			if (!ok) {
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " <<endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(cin);
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: ";
				//Time tina;
				//tina = getWaitTime(*m_lineup[m_lineupSize]);
				cout << getWaitTime(*m_lineup[m_lineupSize]);
				cout << endl << "******************************************" << endl << endl;
				m_lineupSize++;
			}
		}

	}

	void PreTriage::admit() {
		bool ok = true;
		int selection;
		int numIndex;
		char typo = '\0';
		m_pMenu >> selection;
		if (selection == 1)
			typo = 'C';
		if (selection == 2)
			typo = 'T';
		if (selection == 0)
			ok = false;
		if (ok) {
			numIndex = indexOfFirstInLine(typo);
			if (numIndex >= 0 && numIndex < maxNoOfPatients) {
				m_lineup[numIndex]->fileIO(true);
			}
			cout << endl << "******************************************" << endl;
			m_lineup[numIndex]->fileIO(false);
			cout << "Calling for ";
			m_lineup[numIndex]->write(cout);
			cout << "******************************************" << endl << endl;

			setAverageWaitTime(*m_lineup[numIndex]);
			removePatientFromLineup(numIndex);
		}
	}

	void PreTriage::run(void) {
		int selection = -1;
		bool ok = true;
		while (ok) {
			m_appMenu >> selection;
			switch (selection)
			{
			case 0:
				ok = false;
				break;
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			default:
				break;
			}
		}
	}

}