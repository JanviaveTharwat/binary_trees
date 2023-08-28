#include "binary_trees.h"
size_t recurse_the_height(const binary_tree_t *tree);
/**
 * binary_tree_height - gets the height of atree
 * @tree: tree to get its height
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recurse_the_height(tree) - 1);
}
/**
 * recurse_the_height - recurse the tree height
 * @tree: tree to recurse
 *
 * Return: height
 */
size_t recurse_the_height(const binary_tree_t *tree)
{
	size_t R_hight, L_height;

	if (!tree)
		return (0);

	L_height = recurse_the_height(tree->left);
	R_hight = recurse_the_height(tree->right);

	if (L_height > R_hight)
		return (L_height + 1);
	else
		return (R_hight + 1);
}
