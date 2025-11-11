#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char pol[] = {"abcba"};
char NOTpol[] = {"Kitten"};

int check(char* s){
    int right = strlen(s) - 1;
    int left = 0;

    while(left<right){
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else{
            printf("%s - НЕ полиндром\n", s);
            return 0; //exit(1);
            }
        }

    printf("%s - полиндром\n", s);

    return 0;
}

int main(){
    check(pol);
    check(NOTpol);

    return 0;


}
