#include "lists.h"


/**
 * find_listint_loop - finding the loop
 * @head: the head of the list to be searched
 * Return: the adress of the begining or nothing
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp, *p;

	if (head == NULL || head->next == NULL)
		return (NULL);

	p = head->next;
	tmp = head->next->next;
	while (tmp && tmp->next)
	{
		if (p == tmp)
			break;
		p = p->next;
		tmp = tmp->next->next;
	}
	if (p != tmp)
		return (NULL);
	p = head;
	while (p != tmp)
	{
		p = p->next;
		tmp = tmp->next;
	}
	return (p);
}
