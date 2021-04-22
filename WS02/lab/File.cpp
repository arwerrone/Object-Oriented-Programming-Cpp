/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
 
   bool read(char* name) {
       return fscanf(fptr, "%[^\n]\n",name) == 1;

   }
   
   bool read(int &emNo) {
       return fscanf(fptr, "%d,", &emNo) == 1;
   }
   
   bool read(double &salary) {
       return fscanf(fptr, "%lf,", &salary) == 1;
   }
   
}