#include "binary_trees.h"

/**
 * bst_helper - Checks if a binary tree is a valid binary search tree
 * @tree: A pointer to the root node of the tree to check
 * @l: The value of the smallest node visited thus far
 * @h: The value of the largest node visited this far
 * Return: 1 or 0
 */
int bst_helper(const binary_tree_t *tree, int l, int h)
{
	if (tree != NULL)
	{
		if (tree->n < l || tree->n > h)
			return (0);
		return (bst_helper(tree->left, l, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, h));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_helper(tree, INT_MIN, INT_MAX));
}
