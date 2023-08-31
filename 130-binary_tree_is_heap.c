#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree root
 * Return: size of the tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * completed_tree - checks if tree is complete
 * @tree: pointer to the tree root
 * @i: node index
 * @n_node: number of nodes
 * Return: 1 or 0
 */
int completed_tree(const binary_tree_t *tree, int i, int n_node)
{
	if (tree == NULL)
		return (1);

	if (i >= n_node)
		return (0);

	return (completed_tree(tree->left, (2 * i) + 1, n_node) &&
		completed_tree(tree->right, (2 * i) + 2, n_node));
}


/**
 * completed_binary_tree - calls to completed_tree function
 * @tree: tree root
 * Return: 1 or 0
 */
int completed_binary_tree(const binary_tree_t *tree)
{
	size_t n_node;

	if (tree == NULL)
		return (0);

	n_node = binary_tree_size(tree);

	return (completed_tree(tree, 0, n_node));
}

/**
 * parent_checker - checks if parent has a greater value than its childs
 * @tree: pointer to the node
 * Return: 1 or 0
 */
int parent_checker(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (parent_checker(tree->left) && parent_checker(tree->right));
}

/**
 * binary_tree_is_heap - checks if an input tree is a Max Binary Heap
 * @tree: pointer to the root of the tree
 * Return: 1 or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!completed_binary_tree(tree))
		return (0);

	return (parent_checker(tree->left) && parent_checker(tree->right));
}
