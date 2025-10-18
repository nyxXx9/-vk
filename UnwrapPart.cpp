#include <stdio.h>
//------------------------------------------------------------------------------------------------
void swap(int* a, int* b);
//------------------------------------------------------------------------------------------------
int main(){
    int massive[7] = {1, 2, 3, 4, 5, 6, 7};               //вручную задаем массив
    int left = 0;                                         //левый указатель
    int lenght = sizeof(massive) / sizeof(massive[0]);    //длина массива
    int right = lenght - 1;                               //правый указатель
    int k = 0;                                        //часть массива, которую будем переворачивать

    scanf("%d", &k);                                  //считываем k
    /*Печатаем исходный массив*/
    printf("Before\n");
    for (int r = 0; r < 7; r++){
    printf("%d ", massive[r]);
    }

    printf("\n");
    /*Переворачиваем весь массив*/
    while (left < right){
    swap(&massive[left], &massive[right]);

    left += 1;
    right -= 1;
    }

    /*Переворачиваем первые k эл-тов*/
    for (int h = 0; h < k/2; h++){
    swap(&massive[h], &massive[ k-h-1 ]);
    }

    printf("\n");

    /*Переворачиваем последние (lenght - k) эл-ты*/
    for (int l = 0; l < ((lenght - k)/2); l++){  //0
    swap(&massive[l+k], &massive[lenght - l - 1]);
    }
    /*Печатаем развернутый итоговый массив*/
    printf("Unwrap:\n");
    for (int z = 0; z < 7; z++){
    printf("%d ", massive[z]);
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------
void swap(int* a, int* b){
    int t = 0;

    t = *a;
    *a = *b;
    *b = t;
}

