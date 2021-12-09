#include "sort.h"


/**
 * star - getting everythin in place array
 * @arr: the array to sort
 * @s: size of the array
 * @x: entry point
 * @count: all the size
 */
void star(int *arr, size_t s, int x, size_t count)
{
	int i, l, r, z;

	i = x;
	l = 2 * x + 1;
	r = 2 * x + 2;
	if (l < (int)s && arr[l] > arr[i])
		i = l;
	if (r < (int)s && arr[r] > arr[i])
		i = r;
	if (i != x)
	{
		z = arr[x];
		arr[x] = arr[i];
		arr[i] = z;
		print_array(arr, (int)count);
		star(arr, (int)s, i, (int)count);
	}
}

/**
 * heap_sort - heap sort the array
 * @array: to be sorted
 * @size: size of the array to be sorted
 */
void heap_sort(int *array, size_t size)
{
	int i, z;

	if (size == 0)
		return;
	for (i = (int)size / 2 - 1; i >= 0; i--)
		star(array, (int)size, i, size);
	for (i = (int)size - 1; i > 0; i--)
	{
		z = array[0];
		array[0] = array[i];
		array[i] = z;
		print_array(array, (int)size);
		star(array, i, 0, size);
	}
}
