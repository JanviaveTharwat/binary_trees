#include "binary_trees.h"

/**
 * bal_fac - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: void
 */
void bal_fac(avl_t **tree)
{
	int bf;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal_fac(&(*tree)->left);
	bal_fac(&(*tree)->right);
	bf = binary_tree_balance((const binary_tree_t *)*tree);
	if (bf > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bf < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * min_node - get the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int min_node(bst_t *node)
{
	int lf = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		lf = min_node(node->left);
		if (lf == 0)
		{
			return (node->n);
		}
		return (lf);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 or child value
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = min_node(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal_fac(&root_a);
	return (root_a);
}
