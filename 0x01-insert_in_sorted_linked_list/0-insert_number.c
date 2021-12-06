#include "lists.h"

/**
 * insert_node - insert a node in sorted linked list
 * @head: the head of the list to insert in
 * @number: the number to insert
 * Return: the adress of the new node or NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *n, *insert;
    insert = *head;
    n = malloc(sizeof(listint_t));
    if (n == NULL)
        return (NULL);
    n->n = number;
    if(*head == NULL || (*head)->n >= n->n)
    {
        n->next = *head;
        *head = n;
        return (n);
    }
    for (insert = *head; insert != NULL; insert = insert->next)
    {
        if (insert->next == NULL || insert->next->n > n->n)
        {
            n->next = insert->next;
            insert->next = n;
            break;
        }
    }
    return (n);
}
