#include "search.h"

/**
 * linear_skip - give me access
 * @list: the list
 * @value: searched for
 * Return: the list
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int i = 0;
	skiplist_t *he;

	if (!list)
		return (NULL);
	he = list;
	for (list = list->express; list; list = list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (value >= i && value <= list->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", he->index, list->index);
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
		printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, he->index);
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
