#include "lists.h"


/**
 * is_palindrome - check the linked list if it's palindrome ?
 * @head: head of the list
 * Return: 0 if palindrome 1 if not palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *n, *h;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	h = *head;
	while (h->next)
		h = h->next;
	n = *head;
	while (h >= n)
	{
		if (n->n == h->n)
		{
			n = n->next;
			h -= 2;
		}
		else
			return (0);
	}
	return (1);
}
