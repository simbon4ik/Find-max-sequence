#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define default_len 10

int* foo(int* array, int len, int* new_len){
    int cnt = 1;    
    int maximum = 0;            //Количество элементов в макс.посл.
    int index_maximum = 0;      //Индекс, с которого начинается
    int max_sum = 0;            //Максимальная сумма элементов
    int temp_sum = array[0];    //Сумма для каждой последовательности
    for (int i = 1; i < len; ++i){
        if (array[i] > array[i-1]){
            cnt += 1;
            temp_sum += array[i];
        }
        else{
            if (cnt > maximum){     //Если нашли длиннее
                maximum = cnt;
                index_maximum = i;
                max_sum = temp_sum;
            }else{
                if ((cnt == maximum) && (temp_sum > max_sum)){        //Случай, если последовательности равной длины, выбираем с макс.суммой
                    maximum = cnt;
                    index_maximum = i;
                    max_sum = temp_sum;
                }
            }
            cnt = 1;
            temp_sum = array[i];
        }
    }
    max_sum = (max_sum > temp_sum) ? max_sum : temp_sum;
    printf("max count is %d\n", maximum);
    printf("index max count is %d\n", index_maximum);
    printf("max sum is %d\n", max_sum);
    int* result = (int*)malloc(maximum*sizeof(int));
    for (int i = 0; i < maximum; ++i){
        result[i] = array[index_maximum];
        index_maximum += 1;
        printf("result iss %d, index is %d \n", result[i], index_maximum);
    }
    *new_len = maximum;   //Длина результирующего массива
    printf("here is okay\n");
    return result;
}


int main(){
    int *array = (int*)malloc(default_len*sizeof(int));
    int temp[] = {5,7,1,2,3,5,4,10,15,40};      //1,2,3,5 и 4,10,15,40 - две последовательности длины 4, но сумма больше у второй
    memcpy(array, temp, default_len * sizeof(int));
    int new_len = 0;
    int* result = foo(array, default_len, &new_len);
    free(array);
    printf("new_len %d\n",new_len);
    for(int i = 0; i < new_len; ++i){
        printf("%d\n",result[i]);
    }
    free(result);
    return 0;
}
