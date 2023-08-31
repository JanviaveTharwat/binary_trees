#include "binary_trees.h"

/**
 * h_arr - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: position where the array starts
 * @end: position where the array ends
 * Return: tree created
 */
avl_t *h_arr(avl_t *parent, int *array, int begin, int end)
{
	avl_t *root;
	binary_tree_t *h;
	int mid = 0;

	if (begin <= end)
	{
		mid = (begin + end) / 2;
		h = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (h == NULL)
			return (NULL);
		root = (avl_t *)h;
		root->left = h_arr(root, array, begin, mid - 1);
		root->right = h_arr(root, array, mid + 1, end);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - create a alv tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (h_arr(NULL, array, 0, ((int)(size)) - 1));
}
