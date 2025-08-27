#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct {
    int size;      // Size of the array
    int *array;
} Array;

Array creat_array(int size);
void free_array(Array *arr);
int array_size(const Array *arr);
int* array_at(Array *arr,int index);
void array_inflate(Array *arr, int new_size);

#endif