#include "binary_trees.h"
/**
 * binary_tree_delete - deletes whole tree
 * @tree: pointer to root
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		// recursioin the left side
		binary_tree_delete(tree->left);
		// recurse the right side
		binary_tree_delete(tree->right);

		free(tree);
	}
}
