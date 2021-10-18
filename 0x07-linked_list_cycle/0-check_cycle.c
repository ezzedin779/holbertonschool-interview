#include "lists.h"


/**
 * check_cycle - are u cycle ?
 * @list: the list to check
 * Return: 1 if cycle 0 if not
 */
int check_cycle(listint_t *list)
{
	listint_t *ad = list;
	listint_t *no = list;

	if (list == NULL)
		return (0);
	while (no && ad && ad->next)
	{
		ad = ad->next->next;
		no = no->next;
		if (ad == no)
			return (1);
	}
	return (0);
}
