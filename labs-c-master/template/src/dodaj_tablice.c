#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void arr_sum(int16_t* tab1, int16_t* tab2, int16_t arr_length){
    int32_t *ptr = (int32_t *)malloc(arr_length * sizeof(int32_t));
    for(int16_t i=0; i<arr_length; i++)
    {
        ptr[i]=tab1[i]+tab2[i];
        printf("%d ", ptr[i]);
    } 
}

int main(void){
    int16_t tab1[] = {5, 3, 5, 2, 8, 7};
    int16_t tab2[] = {1, 2, 3, 4, 5, 6};
    arr_sum(tab1, tab2, 6);
    return 0;
}
