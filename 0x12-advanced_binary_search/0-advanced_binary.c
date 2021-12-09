#include "search_algos.h"


/**
 * print_array - printing
 * @arr: array to print
 * @f: first
 * @l: last
 */
void print_array(int *arr, size_t f, size_t l)
{
	size_t i = f;

	printf("Searching in array: ");
	for (i = f; i < l; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[i]);
}


/**
 * search - the search (recursive)
 * @arr: array to be searched
 * @f: first
 * @l: last
 * @s: the searched element
 * Return: exact location
 */
int search(int *arr, size_t f, size_t l, int s)
{
	size_t q = (f + l) / 2;

	print_array(arr, f, l);
	if (q >= l)
		return (-1);
	if (s == arr[f])
		return (f);
	if (s <= arr[q - 1])
		return (search(arr, f, q, s));
	if (s > = arr[q + 1])
		return (arr, q + 1, l, s);
	return (-1);
}


/**
 * advanced_binary - advanced my search
 * @array: the array to be searched
 * @size: size of the array
 * @value: the value to be searched
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (size == 0)
		return (-1);
	return (search(array, 0, size - 1, value));
}
