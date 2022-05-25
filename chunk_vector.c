/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press Run button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t* arr[31];
int32_t sz = 0;
int32_t index = 0;
int32_t bucket = 0;

void init(){
    arr[bucket] = malloc((1 << bucket) * sizeof(int32_t));
}

void add(int val){
    if(index >= 1 << bucket){
        bucket++;
        arr[bucket] = malloc((1 << bucket) * sizeof(int32_t));
        index = 0;
    }
    arr[bucket][index] = val;
    index++;
    sz++;
}

int32_t get(int32_t idx){
    //array index out of bounds check omitted
    idx++;
    int high = 32 - __builtin_clz(idx) - 1;
    int low = idx - (1 << (high));
    return arr[high][low];
}
    
int main(){
    
    init();
    
    for(int i = 0; i < 100; i++){
        add(i);
    }
    // arr[0][0] = 5;
    for(int i = 0; i < 100; i++){
        printf("%d " , get(i));
    }
    
}
