#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//----------------------------------------------------------------------------------------------
//прототип ф-ии
bool isPalindrome(char* s);
//-------------------------------------------------------------------------------------------
int main() {
    char str[100];

    printf("Введите строку: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("Строка '%s' является палиндромом\n", str);
    } else {
        printf("Строка '%s' НЕ является палиндромом\n", str);
    }

    return 0;
}
//-------------------------------------------------------------------------------------------
bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

