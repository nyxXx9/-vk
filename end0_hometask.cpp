#include <stdio.h>
//-------------------------------------------------------------------------------------------------
int main(){
    int mark[7] = {1, 0, 5, 0, 3, 0, 8};          //задаем список саморучно
    int length = sizeof(mark)/sizeof(mark[0]);    //вычисляем длину списка
    int pos = 0;                                  //для записи ненулевых элементов

    /* Печатаем исходник */
    printf("До обработки: ");
    for (int k = 0; k < length; k++) {
        printf("%d ", mark[k]);
    }

    /* Переносим ненулевые эл-ты в начало */
    for (int i = 0; i < length; i++){

        if (mark[i] != 0){
            mark[pos] = mark[i];
            pos++;
        }

    }

    /* Заполняем оставшиеся позиции нулями */
    while (pos < length) {

        mark[pos] = 0;
        pos++;

    }

    /* Печатаем результат */
    printf("\nПосле обработки: ");
    for (int k = 0; k < length; k++) {
        printf("%d ", mark[k]);
    }

    return 0;
}
