/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include "Population.h"
#include <iostream>
#include "cstring.h"
#include "File.h"
#include <cstring>
using namespace std;
namespace sdds {

    int noOfPopulations;
    Population* populations;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPopulations - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (populations[j].m_population > populations[j + 1].m_population) {
                    temp = populations[j];
                    populations[j] = populations[j + 1];
                    populations[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& pop) {
        bool ok = false;
        char PCODE[4];
        if (read(PCODE) && read(pop.m_population)) {
            int x = strlen(PCODE);
            pop.m_postalCode = new char[x + 1];
            strcpy(pop.m_postalCode, PCODE);
            ok = true;
        }
        return ok;
    }

    /*bool load(Population& pop) {
        bool ok = false;
        char PCODE[4];
        if (read(PCODE) && read(pop.m_population)) {
            strCpy(pop.m_postalCode, PCODE);
            ok = true;
        }
        return ok;
    }*/
    
    bool load(const char* FILEname) {
        bool ok = false;
        int i = 0, j = 0;
        if (openFile(FILEname)) {

            int x = noOfRecords();
            noOfPopulations = x;
            populations = new Population[noOfPopulations];

            for (i = 0; i < noOfPopulations; i++)
            {
                load(populations[i]);
                j++;
                
            }
            if (x == j) {
                ok = true;
            }
            else {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << FILEname << endl;
        }
        return ok;
    }

    void display(const Population& popul) {
        cout << popul.m_postalCode << ":  " << popul.m_population << endl;
    }

    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        int population = 0;
        for (int i = 0; i < noOfPopulations; i++) {
            cout << i + 1 << "- ";
            display(populations[i]);
            population += populations[i].m_population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << population <<endl;
    }

    void deallocateMemory() {
        int i = 0;
        for (i = 0; i < noOfPopulations; i++) {
            delete[] populations[i].m_postalCode;
            populations[i].m_postalCode = nullptr;
        }
        delete[] populations;
        populations = nullptr;
    }

    /*void deallocateMemory() {
        int i = 0;
        for (i = 0; i < noOfPopulations; i++) {
            delete[] populations;
            populations = nullptr;
        }
    }*/

}