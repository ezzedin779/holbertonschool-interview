#include "binary_trees.h"

/**
 * crnode - create NODE ?
 * @arr: array
 * @h: head of the element
 * @fir: first element
 * @l: last element
 * Return: new list left/right
 */
avl_t *crnode(int arr, avl_t *h, int fir, int l)
{
	int mid;
	avl_t *n;

	if (fir >l)
		return(NULL);

	mid = (fir + l) / 2;
	n = malloc(sizeof(avl_t));

	if (!n)
		return(NULL);

	n->n = arr[mid];
	n->parent = h;
	n->right = crnode(arr, n, mid + 1, l);
	n->left = crnode(arr, n, fir, mid - 1);
	return(n);
}


/**
 *sorted_array_to_avl - get the array
 *@array: array to print
 *@size: size of the array
 *Return: Binary Tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *s;
	int fir, mid, l:

	if (!array)
		return(NULL);
	s = malloc(sizeof(avl_t));
	if (!s)
		return(NULL);
	fir = 0;
	l = size - 1;
	mid = (fir + l) / 2;
	s->n = array[mid];
	s->parent = NULL;
	s->right = crnode(array, s, mid + 1, l);
	s->left = crnode(array, s, fir, mid - 1);
}
