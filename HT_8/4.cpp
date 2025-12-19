#include <stdbool.h>

bool canMakeValid(char* s, int k) {
    int balance = 0, extra = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            balance++;
        } else {
            if (balance > 0) balance--;
            else extra++;
        }
    }
    return balance + extra <= k;
}
