#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//----------------------------------------------------------------------------------------------
//прототипы ф-ий
bool isSubsequence(char* a, char* b);
//----------------------------------------------------------------------------------------------
int main() {
    char a[100], b[100];

    printf("Введите исходную строку a: ");
    scanf("%s", a);

    printf("Введите строку b: ");
    scanf("%s", b);

    if (isSubsequence(a, b)) {
        printf("Строка '%s' является исходной для '%s'\n", a, b);
    } else {
        printf("Строка '%s' НЕ является исходной для '%s'\n", a, b);
    }

    return 0;
}
//----------------------------------------------------------------------------------------------
bool isSubsequence(char* a, char* b) {
    int i = 0, j = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);

    while (i < len_a && j < len_b) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }
    return i == len_a;
}

