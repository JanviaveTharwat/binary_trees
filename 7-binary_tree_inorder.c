#include "binary_trees.h"
/**
 * binary_tree_inorder - traverse tree using in-order method
 * @tree: pointer to the root
 * @func: function pointer to check each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
