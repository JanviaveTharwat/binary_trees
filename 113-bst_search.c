#include "binary_trees.h"

/**
 * bst_search - searches for a value in BST
 * @tree: pointer to the root
 * @value: value to search
 * Return: the binary tree
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}

	if (tree->n == value)
	{
		return ((bst_t *)tree);
	}

	if (tree->n > value)
	{
		return (bst_search(tree->left, value));
	}
	else
	{
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
