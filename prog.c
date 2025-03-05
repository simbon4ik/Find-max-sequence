#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define default_len 10

int* foo(int* array, int len, int* new_len){
    int cnt = 1;
    int maximum = 0;
    int index_maximum = 0;
    for (int i = 1; i < len; ++i){
        if (array[i] > array[i-1]){
            cnt += 1;
        }
        else{
            maximum = (maximum > cnt) ? maximum : cnt;          //Количество эл. в макс. последовательности
            index_maximum = (maximum > cnt) ? i : index_maximum;    //Индекс, с которого она начинается
            cnt = 1;
        }
    }
    printf("max count is %d\n", maximum);
    printf("index max count is %d\n", index_maximum);
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
    int temp[] = {2, 5, 3, 1, 15, 19, 23, 4, 9, 10};
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
