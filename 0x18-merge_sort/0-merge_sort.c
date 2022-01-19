#include "sort.h"


/**
 * top_merge - getting element in the new array
 * @arr: to split
 * @fir: first element
 * @mid: middle
 * @la: last element
 * @narr: new array
 */
void top_merge(int *arr, int fir, int mid, int la, int *narr)
{
	int i = fir;
	int j = mid;
	int k = 0;

	for (k = fir; k < la; k++)
	{
		if (i < mid && (j >= la || narr[i] <= narr[j]))
		{
			arr[k] = narr[i];
			i++;
		}
		else
		{
			arr[k] = narr[j];
			j++;
		}
	}
}

/**
 * top_split - splitting array ?
 * @arr: the array to split
 * @fir: first element
 * @la: last element
 * @narr: the new array splitted ?
 */

void top_split(int *narr, int fir, int la, int *arr)
{
	int mid;
	int i = 0;

	if (la - fir <= 1)
		return;
	
	mid = (la + fir) / 2;

	top_split(arr, fir, mid, narr);
	top_split(arr, mid, la, narr);

	printf("Merging...\n");
	printf("[left]: ");

	for (i = fir; i < mid; i++)
	{
		printf("%d", narr[i]);
		if (i < mid - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (i = mid; i < la; i++)
	{
		printf("%d", narr[i]);
		if (i < la - 1)
			printf(", ");
	}

	top_merge(arr, fir, mid, la, narr);

	printf("\n");
	printf("[Done]: ");
	for (i = fir; i < la; i++)
	{
		printf("%d", arr[i]);
		if (i < la - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * top_sort - top down method to sort
 * @arr: the array to sort
 * @narr: the sorted array
 * @size: the size of the array
 */

void top_sort(int *arr, int *narr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		narr[i] = arr[i];
	top_split(narr, 0, size, arr);
}

/**
 * merge_sort - merge sorting ?
 * @array: the array to sort
 * @size: len of the array
 */
void merge_sort(int *array, size_t size)
{
	int *narr;

	if (array == NULL)
		return;
	
	narr = malloc(sizeof(int) * size);

	top_sort(array, narr, size);
	free(narr);
}
