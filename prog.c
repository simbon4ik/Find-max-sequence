#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define default_len 10

int* foo(int* array, int len, int* new_len);

int main(){
    int *array = (int*)malloc(default_len*sizeof(int));
    int temp[] = {5,7,2,3,5,6,4,10,15,40};      //2,3,5,6 и 4,10,15,40 - две последовательности длины 4, но сумма больше у второй
    memcpy(array, temp, default_len * sizeof(int));
    int new_len = 0;
    int* result = foo(array, default_len, &new_len);
    free(array);
    printf("Result is: ");
    for(int i = 0; i < new_len; ++i){
        printf("%d ",result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}


int* foo(int* array, int len, int* new_len){
    int cnt = 1;    
    int maximum = 0;            //Количество элементов в макс.посл.
    int temp_ind = 0;           //Временный индекс
    int index_maximum = 0;      //Индекс, с которого начинается
    int max_sum = 0;            //Максимальная сумма элементов
    int temp_sum = array[0];    //Сумма для каждой последовательности
    for (int i = 1; i < len; ++i){
        if (array[i] > array[i-1]){
            cnt += 1;
            temp_sum += array[i];
            if (i != len-1) continue;     //Если последний элемент, чтобы обновить max_sum и все остальное
        }
        if (cnt > maximum){     //Если нашли длиннее
            maximum = cnt;
            index_maximum = temp_ind;
            max_sum = temp_sum;
        }
        if ((cnt == maximum) && (temp_sum > max_sum)){        //Случай, если последовательности равной длины, выбираем с макс.суммой
            maximum = cnt;
            index_maximum = temp_ind;
            max_sum = temp_sum;
        }
        cnt = 1;                //Обновление счетчика длины
        temp_sum = array[i];    //Обновление суммы
        temp_ind = i;           //Обновление индекса
    }
    int* result = (int*)malloc(maximum*sizeof(int));
    for (int i = 0; i < maximum; ++i){
        result[i] = array[index_maximum];
        index_maximum += 1;
    }
    *new_len = maximum;   //Длина результирующего массива
    return result;
}

