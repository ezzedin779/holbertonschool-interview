#include "binary_trees.h"

/**
 * bst - Maximum side
 * @tree: tree to check
 * @min: minimum ?
 * @max: Maximum
 * Return: An integer ?
 */
int bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst(tree->left, min, tree->n - 1) &&
				bst(tree->right, tree->n + 1, max));
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
		return (0);

	if (!bst(tree, INT_MIN, INT_MAX))
		return (0);

	lh = hieght(tree->left);
	rh = height(tree->right);

	if (abs(rh - lh) > 1)
		return (0);

	if (!(tree->left) || !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
