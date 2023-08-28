#include "binary_trees.h"
/**
 * binary_tree_is_root - check if node is the root node
 * @node: pointer to the node
 *
 * Return: 1 if root Or 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL)
		if (node->parent == NULL)
			return (1);
	return (0);
}
