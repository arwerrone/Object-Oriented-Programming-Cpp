/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

  
   bool load(Employee& st) {
      bool ok = false;
      char name[128];
      if (read(st.m_empNo) && read(st.m_salary) && read(name)) {
          int x = strLen(name);
          st.m_name = new char[x + 1];
          strCpy(st.m_name, name);
          return true;
      }
      return ok;
   }
   bool load() {
      bool ok = false;
      int i = 0, j = 0;
      if (openFile(DATAFILE)) {
          
          int x = noOfRecords();
          noOfEmployees = x;
          employees = new Employee[noOfEmployees];

          for (i = 0; i < noOfEmployees; i++)
          {
              load(employees[i]);
              j++;
              /*
              if (load(employees[i]) == true){
                j++;
              }
              */
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
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   void display(const Employee& emp) {
       cout << emp.m_empNo<<": " << emp.m_name <<", " << emp.m_salary << endl;
   }

   void display() {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       
       for (int i = 0;i < noOfEmployees; i++) {
           cout << i+1 << "- ";
           display(employees[i]);

       }
   }

   void deallocateMemory() {
       int i = 0;
       for (i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
           employees[i].m_name = nullptr;
       }
       delete[] employees;
       employees = nullptr;
   }

}