#include "binary_trees.h"

/**
 * binary_tree_depth - Measures a binary tree node's depth
 * @tree: A pointer to the node to measure the depth
 * Return: 0 or the depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
