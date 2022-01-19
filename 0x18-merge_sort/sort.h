#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void top_merge(int *arr, int fir, int mid, int la, int *narr);
void top_split(int *narr, int fir, int la, int *arr);
void top_sort(int *arr, int *narr, int size);

#endif
