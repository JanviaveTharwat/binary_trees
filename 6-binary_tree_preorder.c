#include "binary_trees.h"

/**
 * binary_tree_preorder - uses pre-order traversal to go through a binary tree
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 * return : void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
