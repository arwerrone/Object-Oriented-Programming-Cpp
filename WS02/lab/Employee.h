/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#include "File.h"
#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    
    void sort();
    bool load(Employee& st); 
    bool load();
    void display(const Employee& emp);
    void display();
    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_