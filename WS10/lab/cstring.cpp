#include <iostream>
#include "cstring.h"

using namespace std;
namespace sdds {

    void strCpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

    void strnCpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; i < len && src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        while (i < len) {
            des[i] = '\0';
            i++;
        }
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

    int strnCmp(const char* s1, const char* s2, int len) {
        int i;
        for (i = 0; i< len; i++) {

            if (s1[i] == s2[i]) {
                if (i == (len - 1)) {
                    return 0;
                }
            }

            if (s1[i] > s2[i]) {
                return 1;
            }

            if (s1[i] < s2[i]) {
                return -1;
            }
        }
        return 0;
    }
 
    int strLen(const char* s) {
        int x = 0, i = 0;
        for (i = 0; s[i] != '\0'; i++) {
            x++;
        }
        return x;
    }

    const char* strStr(const char* str1, const char* str2) {
        const char* a, *b;

        b = str2;

        if (*b == 0) {
            return (char*)str1;
        }

        for (; *str1 != 0; str1 += 1) {
            if (*str1 != *b) {
                continue;
            }

            a = str1;
            while (true) {
                if (*b == 0) {
                    return (char*)str1;
                }
                if (*a++ != *b++) {
                    break;
                }
            }
            b = str2;
        }
        return nullptr;
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
