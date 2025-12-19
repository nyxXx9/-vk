#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 256

char extraLetter(char* a, char* b) {
    int count[TABLE_SIZE] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        count[(unsigned char)a[i]]++;
    }

    for (int i = 0; b[i] != '\0'; i++) {
        count[(unsigned char)b[i]]--;
        if (count[(unsigned char)b[i]] < 0) {
            return b[i];
        }
    }

    return '\0';
}
