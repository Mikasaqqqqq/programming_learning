#include "array.h"
#include <stdlib.h>
#include <stdio.h>

const int BLOCK_SIZE=100;

// typedef struct {
//     int size;      // Size of the array
//     int *array;
// } Array;

Array creat_array(int size)
{
    Array arr;
    arr.size=size;
    arr.array=(int *)malloc(sizeof(int)*size);
    return arr;
}

void free_array(Array *arr)
{
    free(arr->array);
    arr->size=0;
    arr->array=NULL;
    return ;
}

int array_size(const Array *arr)
{
    return arr->size;
}

int* array_at(Array *arr,int index)
{
    if(arr->size>=index)
    {
        array_inflate(arr,(index/BLOCK_SIZE+1)*BLOCK_SIZE-arr->size);
    }
    return arr->array[index];
}

void array_inflate(Array *arr, int new_size)
{
    int *p=(int*)malloc(sizeof(int)*(arr->size+new_size));
    memcpy(p,arr->array,arr->size);
    free(arr->array);
    arr->array=p;
    arr->size+= new_size;
    return ;
}