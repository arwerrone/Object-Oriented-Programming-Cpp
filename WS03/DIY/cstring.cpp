#include "cstring.h"
namespace sdds {

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

}
