#include "binary_trees.h"
binary_tree_t *recurse_ancestor(binary_tree_t *root,
	const binary_tree_t *first, const binary_tree_t *second);
/**
 * binary_trees_ancestor - find lowest common ancestor
 * @first: first node to find its ancestors
 * @second: second node to find its ancestors
 *
 * Return: lowest common ancestor Otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	binary_tree_t *root_node = NULL;

	if (!first || !second)
		return (NULL);

	/* find root node */
	root_node = (binary_tree_t *)first;
	while (root_node->parent != NULL)
		root_node = root_node->parent;

	/* perform lowest common anscestor detection */
	return (recurse_ancestor(root_node, first, second));
}
/**
 * recurse_ancestor - recursive to find lowest ancestor
 * @root: pointer to root
 * @first: pointer to one child
 * @second: pointer to other child
 *
 * Return: pointer to lower ancestor
 */
binary_tree_t *recurse_ancestor(binary_tree_t *root,
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *left_ancestor = NULL, *right_ancestor = NULL;

	if (root == NULL || first == NULL || second == NULL)
		return (NULL);

	if (root == first || root == second)
		return (root);

	left_ancestor = recurse_ancestor(root->left, first, second);
	right_ancestor = recurse_ancestor(root->right, first, second);

	if (left_ancestor && right_ancestor)
		return (root);

	if (left_ancestor != NULL)
		return (left_ancestor);
	return (right_ancestor);
}
