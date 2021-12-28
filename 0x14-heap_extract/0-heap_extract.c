#include "binary_trees.h"


/**
 * Lgth - how long is the tree ?
 * @root: the root
 * Return: the length of the tree
 */
int lgth(heap_t *root)
{
	int l = 0;
	int r = 0;

	if (root == NULL)
		return (0);

	l = lgth(root->left);
	r = lgth(root->right);

	if (l > r)
		return (l + 1);
	else
		return (r + 1);
}

/**
 * lf - the leaf
 * @root: the root
 * Return: the leaf element
 */
heap_t *lf(heap_t *root)
{
	if (root == NULL)
		return (NULL);
	if (!root->right && !root->left)
		return (root);

	if (lgth(root->left) > lgth(root->right))
		return (lf(root->left));
	return (lf(root->right));
}

/**
 * swap - swap
 * @first: first element
 * @second: second element
 */
void swap(heap_t *first, heap_t *second)
{
	int z = second->n;

	second->n = first->n;
	first->n = z;
}
/**
 * fix - fixing my first
 * @first: the element
 */
void fix(heap_t **first)
{
	heap_t *tobe = (*first);

	while ((tobe->left && tobe->n < tobe->left->n) ||
					(tobe->right && tobe->n < tobe->right->n))
	{
		if (tobe->right && tobe->left)
			tobe = tobe->left->n > tobe->right->n ? tobe->left : tobe->right;
		if (tobe->right && tobe->right->n > tobe->n)
			tobe = tobe->right;
		else if (tobe->left && tobe->left->n > tobe->n)
			tobe = tobe->left;
		
		swap(tobe->parent, tobe);
	}	
}

/**
 * heap_extract - to extract
 * @root: the head
 * Return: the extracted
 */
int heap_extract(heap_t **root)
{
	heap_t *lol, *tp;
	int value;

	if((*root) == NULL)
		return (0);

	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free((*root));
		*root = NULL;
		return (value);
	}
	lol = lf((*root));

	if (lol == NULL)
		return (0);
	tp = (*root);
	if (tp->left)
	{
		tp->left->parent = lol;
		lol->left = tp->left;
	}
	if (tp->right)
	{
		tp->right->parent = lol;
		lol->right = tp->right;
	}
	if (lol->parent->left && lol->parent->left == lol)
		lol->parent->left = NULL;
	else if (lol->parent->right && lol->parent->right == lol)
		lol->parent->right = NULL;

	lol->parent = tp->parent;
	(*root) = lol;

	free(tp);
	fix(root);

	return (value);
}
