#include "binary_trees.h"

/**
 * _depth - how deep ?
 * @tree: the tree to climb
 * Return: the _depth
 */
size_t _depth(const heap_t *tree)
{
	size_t d = 0;

	if (tree == NULL)
		return (d);
	while (tree->parent)
	{
		d++;
		tree = tree->parent;
	}
	return (d);
}

/**
 * _is_leaf - are u the last ?
 * @n: the node to check
 * Return: 0 or 1
 */
int _is_leaf(const heap_t *n)
{
	if (n == NULL)
		return (0);
	else if (n->left == NULL && n->right == NULL)
		return (1);
	return (0);
}

/**
 * _height - how long ? ?
 * @tree: the tree to check
 * Return: the height
 */
size_t _height(const heap_t *tree)
{
	size_t left, right;

	if (tree == NULL || _is_leaf(tree))
		return (0);
	left = _height(tree->left);
	right = _height(tree->right);
	if (right <= left)
		return (left + 1);
	return (right + 1);
}

/**
 * _insert - insert it
 * @tree: the tree to insert in
 * @l: how deep ?
 * @value: the value to insert
 * Return: the inserted position
 */
binary_tree_t *_insert(binary_tree_t *tree, size_t l, int value)
{
	binary_tree_t *le, *ri;

	if (tree == NULL)
		return (NULL);
	if (_depth(tree) == l)
	{
		if (_is_leaf(tree))
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left != NULL && tree->right == NULL)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	le = _insert(tree->left, l, value);
	if (le == NULL)
		ri = _insert(tree->right, l, value);
	else
		return (le);
	return (ri);
}

/**
 * heap_insert - insert in the heapp
 * @root: the root node of the heap
 * @value: the new value to add
 * Return: the inserted new thing or null
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t l, i, tmp = 0;
	heap_t *n = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node((binary_tree_t *)*root, value);
		return (*root);
	}
	l = _height(*root);
	for (i = 0; i <= l; i++)
	{
		n = (heap_t *)_insert((binary_tree_t *)*root, i, value);
		if (n != NULL)
			break;
	}
	while (n->parent != NULL && n->n > n->parent->n)
	{
		tmp = n->parent->n;
		n->parent->n = n->n;
		n->n = tmp;
		n = n->parent;
	}
	return (n);
}
