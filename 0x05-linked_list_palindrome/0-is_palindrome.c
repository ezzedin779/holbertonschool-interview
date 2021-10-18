#include "lists.h"

/**
 * _length - calculate the length of a linked list
 * @head: the head of the list
 * Return: the length
 */
int _length(listint_t *head)
{
	listint_t *n = head;
	int len = 1;

	while (n->next != NULL)
	{
		len++;
		n = n->next;
	}
	return (len);
}

/**
 * is_palindrome - check the linked list if it's palindrome ?
 * @head: head of the list
 * Return: 0 if palindrome 1 if not palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *h = *head;
	int len = _length(*head);
	int *new = malloc((len / 2) * sizeof(int));
	int i, count = 0;

	if (!head)
		return (0);
	if (!(*head))
		return (1);
	for (count = 0; count != len / 2; count++)
	{
		new[count] = h->n;
		h = h->next;
	}
	if (len % 2 != 0)
		h = h->next;
	for (i = (len / 2) - 1; i != -1; i--)
	{
		if (h->n != new[i])
		{
			free(new);
			return (0);
		}
		h = h->next;
	}
	free(new);
	return (1);
}
