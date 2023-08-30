#include "binary_trees.h"
bst_t *recurse_bst_insert(bst_t *tree, int value);
bst_t *bst_insert(bst_t **tree, int value);
void recurse_balance(binary_tree_t *tree);
/**
 * avl_insert - insert node into AVL
 * @tree: pointer to root
 * @value: value to be inserted
 *
 * Return: pointer to new node
 */
avl_t *avl_insert(avl_t **tree, int value)
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

	if (value < parent_node->n)
		parent_node->left = new;
	else
		parent_node->right = new;

	/* re-balance tree */
	recurse_balance(new);

	return (new);
}
/**
 * recurse_balance - recurse from new node
 * @tree: pointer to root
 */
void recurse_balance(binary_tree_t *tree)
{
	int Factor;

	if (!tree)
		return;

	printf("tree (in balance) = %d\n", tree->n);

	Factor = binary_tree_balance(tree);

	if (Factor < -1)
	{
		binary_tree_print(tree);
		tree = binary_tree_rotate_right(tree);
		printf("Rotated right\n");
	}
	else if (Factor > 1)
	{
		binary_tree_print(tree);
		tree = binary_tree_rotate_left(tree);
		printf("Rotated left\n");
	}
	recurse_balance(tree->parent);
}
/**
 * recurse_bst_insert - recursively search tree
 * @tree: pointer to root
 * @value: value
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
