#include "binary_trees.h"

/**
 * bst_h - Maximum side
 * @tree: tree to check
 * @min: minimum ?
 * @max: Maximum
 * Return: An integer ?
 */
int bst_h(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return(1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_h(tree->left, min, tree->n - 1) &&
			bst_h(tree->right, tree->n, tree->n + 1, max));
}

/**
 * bst - minimising my bst_h
 * @tree: the tree to check ?
 * Return: the integer needed ?
 */
int bst(const binary_tree_t *tree)
{
	return (bst_h(tree, INT_MIN, INT_MAX));
}

/**
 * Max - calculating the maximum
 * @x: the variable to check ? 
 * @y: the variable to check ?
 * Return: the biggest ?
 */
int Max(int x, int y)
{
	return ((x >= y) ? x : y);
}

/**
 * height - the height of the tree ?
 * @tree: the tree to check
 * Return: the height of the tree ?
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + Max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - checking if it's avl or not ?
 * @tree: tree to check
 * Return: an avl or not ?
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lh;
	int rh;

	if (tree == NULL)
		return (1);
	if (!bst(tree))
		return (0);
	if (bst(tree))
	{
		lh = height(tree->left);
		rh = height (tree->right);
		if (abs(lh - rh) <= 1 && binary_tree_is_avl(tree->left) &&
				binary_tree_is_avl(tree->right))
			return (1);
	}
	return (0);
}
