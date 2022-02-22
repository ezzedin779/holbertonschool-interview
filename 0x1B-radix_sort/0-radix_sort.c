#include "sort.h"

/**
 * Big - highest element in array
 * @arr: array to search in
 * @size: size of array
 * Return: Biggest element
 */
int Big(int *arr, size_t size)
{
	size_t i;
	int j;
	int tmp = 0;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		tmp = arr[i];
		for (j = 0; tmp; j++)
			tmp = tmp / 10;
		if (j > max)
			max = j;
	}
	return (max);
}

/**
 * radix_sort - sorts with radix sort
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *places[9];
	int sort[9];
	int m;
	int tmp = 0;
	int f = 0;
	int b = 0;
	int sf = 0;
	int count = 0;
	size_t i = 0;

	if (size < 2)
		return;
	m = Big(array, size);
	for (f = 0; f < m; f++)
	{
		for (i = 0; i <= 9; i++)
		{
			sort[i] = 0;
			places[i] = (int *)malloc(sizeof(int) * 1024);
			places[i][0] = -1;
		}
		for (i = 0; i != size; i++)
		{
			tmp = array[i];
			for (b = 0; b < f; b++)
				tmp = tmp / 10;
			sf = tmp % 10;
			places[sf][sort[sf]] = array[i], sort[sf] += 1;
		}
		for (i = 0, count = 0; i <= 9; i++)
			for (b = 0; b < sort[i] && places[i][0] != -1; b++, count++)
				array[count] = places[i][b];
		for (i = 0; i <= 9; i++)
			free(places[i]);
		print_array(array, size);
	}
}
