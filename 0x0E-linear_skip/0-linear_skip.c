#include "search.h"

/**
 * l_s - give me access
 * @l: the list
 * @val: searched for
 * Return: the list
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int i = 0;
	skiplist_t *he;

	if (!l)
		return (NULL);
	he = l;
	for (list = list->express; list; list = list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (val >= i && val <= list->n)
		{
			printf("Value found between indexed [%lu] = [%d]\n", he->index, he->n);
			for (; he != list; he = he->next)
			{
				printf("Value checked at index [%lu] = [%d]\n", he->index, he->n);
				if (he->n == value)
					return (he);
			}
		}

		if (!list->express)
		{
			for (; he->next; he = he->next)
		{}
		printf("Value found between indexes [%lu] and [%lu]\n", list->index, he->index);
		for (; list; list = list->next)
		{
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (list->n == value)
			return (list);
		if (!list->next)
			break;
		}
		}
	i = list->n;
	he = list;
	}
	return (list);
}