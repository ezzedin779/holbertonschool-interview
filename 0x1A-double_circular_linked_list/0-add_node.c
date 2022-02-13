#include "list.h"

/**
 * add_node_end - add a node to the end of the circular list
 * @list: the list to add to
 * @str: the string of the new node
 * Return: Null or Adress new node
 */
List *add_node_end(List **list, char *str)
{
	List *n = NULL;

	n = malloc(sizeof(List));
	if (!n)
		return (NULL);
	n->str = strdup(str);
	if (!n->str)
	{
		free(n);
		return (NULL);
	}
	n->next = NULL;
	n->prev = NULL;
	if (!(*list))
	{
		n->next = n;
		n->prev = n;
		*list = n;
	}
	else
	{
		n->next = (*list);
		n->prev = (*list)->prev;
		(*list)->prev->next = n;
		(*list)->prev = n;
	}
	return (n);
}

/**
 * add_node_begin - adding a node to the beginning
 * @list: the list to add to
 * @str: string of the node
 * Return: new adress or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *n = NULL;

	n = malloc(sizeof(List));
	if (!n)
		return (NULL);
	n->str = strdup(str);
	if (!n->str)
	{
		free(n);
		return (NULL);
	}
	n->next = NULL;
	n->prev = NULL;
	if (!(*list))
	{
		n->next = n;
		n->prev = n;
		*list = n;
	}
	else
	{
		n->next = (*list);
		n->prev = (*list)->prev;
		(*list)->prev->next = n;
		(*list)->prev = n;
		*list = n;
	}
	return (n);
}
