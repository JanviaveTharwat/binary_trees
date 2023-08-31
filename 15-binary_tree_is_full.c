#include "binary_trees.h"
int recurse_check_full(const binary_tree_t *tree);
/**
 * binary_tree_is_full - checks if tree is full
 * @tree: the tree
 *
 * Return: 1 if full 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recurse_check_full(tree));
}
/**
 * recurse_check_full - recursive func
 * @tree: the tree
 *
 * Return: 1 if full 0 otherwise
 */
int recurse_check_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (recurse_check_full(tree->left) * recurse_check_full(tree->right));
}
