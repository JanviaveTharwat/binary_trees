#include "binary_trees.h"
int recurse_complete(const binary_tree_t *tree, size_t index, size_t size);
size_t binarytree_size(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - checks if tree is complete
 * @tree: pointer to root
 *
 * Return: 1 if complete 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recurse_complete(tree, 0, binarytree_size(tree)));
}
/**
 * recurse_complete - indexing to track node position
 * @tree: root of tree
 * @index: index of node in array
 * @size: number of nodes in tree
 *
 * Return: 1 if complete 0 Otherwise
 */
int recurse_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	int lsize, rsize;

	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	lsize = recurse_complete(tree->left, (2 * index) + 1, size);
	rsize = recurse_complete(tree->right, (2 * index) + 2, size);

	if (lsize == 1 && rsize == 1)
		return (1);
	else
		return (0);
}
/**
 * binarytree_size - gets the size
 * @tree: the tree
 *
 * Return: size
 */
size_t binarytree_size(const binary_tree_t *tree)
{
	if (tree)
		return (binarytree_size(tree->left) + 1 + binarytree_size(tree->right));
	return (0);
}
