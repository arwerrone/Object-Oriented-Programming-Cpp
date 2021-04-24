/**
 * Name:			Angelo Dikon Wong
 * Student ID:		148021199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section: OOP244 - NGG
 **/

#include "cstring.h"
namespace sdds {

    int strLen(const char* s) {
        int x = 0, i = 0;
        for (i = 0; s[i] != '\0'; i++) {
            x++;
        }
        return x;
    }

    int strCmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; ; ++i) {
            if (s1[i] > s2[i])
                return 1;
            else
                if (s1[i] < s2[i])
                    return -1;
                else
                    if (s1[i] == '\0' && s2[i] == '\0')
                        return 0;
        }

    }

    void strCpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

}