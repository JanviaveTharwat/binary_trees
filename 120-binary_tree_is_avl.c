#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int _avl_helper(const binary_tree_t *tree, int l, int h);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: 0 or height
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lf = 0, rt = 0;

		lf = tree->left ? 1 + height(tree->left) : 1;
		rt = tree->right ? 1 + height(tree->right) : 1;
		return ((lf > rt) ? lf : rt);
	}
	return (0);
}

/**
 * _avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @l: The value of the smallest node visited thus far.
 * @h: The value of the largest node visited this far.
 * Return: 1 or 0
 */
int _avl_helper(const binary_tree_t *tree, int l, int h)
{
	size_t lf, rt, diff;

	if (tree != NULL)
	{
		if (tree->n < l || tree->n > h)
			return (0);
		lf = height(tree->left);
		rt = height(tree->right);
		diff = lf > rt ? lf - rt : rt - lf;
		if (diff > 1)
			return (0);
		return (_avl_helper(tree->left, l, tree->n - 1) &&
			_avl_helper(tree->right, tree->n + 1, h));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_avl_helper(tree, INT_MIN, INT_MAX));
}
