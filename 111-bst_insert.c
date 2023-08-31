#include "binary_trees.h"
bst_t *recurse_bst_insert(bst_t *tree, int value);
/**
 * bst_insert - insert node into BST
 * @tree: pointer to root
 * @value: value to be stored
 *
 * Return: pointer to new node or NULL Otherwise
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL, *parent_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	parent_node = recurse_bst_insert(*tree, value);

	if (parent_node)
		new = binary_tree_node(parent_node, value);
	else
		return (NULL);

	/* point parent to new node */
	if (value < parent_node->n)
		parent_node->left = new;
	else
		parent_node->right = new;

	return (new);
}
/**
 * recurse_bst_insert - recursively search tree
 * @tree: pointer to root
 * @value: value to be stored
 *
 * Return: pointer to parent of new node or NULL
 */
bst_t *recurse_bst_insert(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value < tree->n)
	{
		if (tree->left != NULL)
			return (recurse_bst_insert(tree->left, value));
		else
			return (tree);
	}

	else if (value > tree->n)
	{
		if (tree->right != NULL)
		{
			return (recurse_bst_insert(tree->right, value));
		}
		else
			return (tree);
	}

	return (NULL);
}
