#include <stdio.h>
#include <stdlib.h>
#include <cstring>

char A[4] = {"abc"};
char B[6] = {"gajbm"};

int main(){
    int i = 0, k = 0;
    while (i < strlen(A) && k < strlen (B)){
        if (A[i] == B[k]){
            i++;
            k++;
        }
        else{
            k++;
        }
    }

    if (i == strlen(A)){
        printf("A исходна для строки B");
    }
    else{
        printf("A НЕ исходна для строки B");
    }

}
