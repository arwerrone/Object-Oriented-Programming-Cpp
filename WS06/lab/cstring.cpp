/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include "cstring.h"
namespace sdds {
 
    void strCpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

    int strLen(const char* s) {
        int x = 0, i = 0;
        for (i = 0; s[i] != '\0'; i++) {
            x++;
        }
        return x;
    }

    void strCat(char* des, const char* src) {
        int x, i;

        for (i = 0; des[i] != '\0'; i++);
        for (x = 0; src[x] != '\0'; x++) {
            des[i + x] = src[x];
        }
        des[i + x] = '\0';
    }

}