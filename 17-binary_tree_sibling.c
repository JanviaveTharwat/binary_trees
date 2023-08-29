#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_sibling - gets sibling node
 * @node: node to find sibling of it
 *
 * Return: pointer to sibling node or NULL on failure
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
	{
		return (node->parent->right);
	}
	else
		return (node->parent->left);
}
