#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate binary tree to the right
 * @tree: pointer to the root
 *
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	binary_tree_t *new_node = NULL, *root_node = NULL;


	if (tree == NULL)
		return (tree);

	/* if root node has no children */
	if ((tree->left == NULL) && (tree->right == NULL))
		return (tree);

	new_node = tree->left;
	tree->left = new_node->right;
	if (new_node->right != NULL)
		new_node->right->parent = tree;

	new_node->parent = tree->parent;

	if (tree->parent == NULL)
		root_node = new_node;
	else if (tree == tree->parent->right)
		tree->parent->right = new_node;
	else
		tree->parent->left = new_node;
	/* move tree to the right of new */
	new_node->right = tree;
	tree->parent = new_node;
	/* if current root is not NULL, return it, otherwise return new root*/
	if (root_node)
		return (root_node);
	return (new_node);
}
