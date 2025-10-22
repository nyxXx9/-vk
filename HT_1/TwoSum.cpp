#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//------------------------------------------------------------------------------------------------
int compare_int(const void *a, const void *b);    //прототип ф-ии
int compare(int* target, int* num, int* length);  //прототип ф-ии сравнения суммы и загаданного числа
//------------------------------------------------------------------------------------------------
int main(){
    int target = 0;
    int num[10] = {0};
    int length = sizeof(num) / sizeof(num[0]);

    srand(time(NULL));                            //чтобы каждый раз выдавался новый набор чисел
    scanf("%d", &target);                         //считываем загаданное число

    for (int i = 0; i < 10; i++){
        num[i] = rand()%20-10;                   //рандомим массив
    }

    qsort((num), 10, sizeof(int), compare_int);  //сортируем массив
/*Печатаем заданное число и данный нам массив*/
    printf("target = %d\n", target);

    printf("Massive: ");
    for (int j = 0; j <  10; j++){
        printf("%d ", num[j]);
    }

    compare(&target, num, &length);              //сравниваем сумму и target (вызов функции)

    return 0;
}

int compare_int(const void *a, const void *b) {
        return (*(int*)a - *(int*)b);            //сравнивает числа и возвращает их разницу
    }
/*Функция сравнения суммы и загаданного числа*/
int compare(int* target, int* num, int* length){
    int left = 0;
    int right = *length - 1;

    while (left < right){
        int sum = num[left] + num[right];


        if (sum < *target){
            left += 1;
        }

        if (sum > *target){
            right -= 1;
        }

        if (sum == *target){
            printf("\nleft=%d and right=%d", left, right);
            break;
        }
    }

/*Если пара не найдена- уведомляем пользователя*/
    if (left >= right) {
            printf("\nПара не найдена\n");
        }

    return 0;
}

