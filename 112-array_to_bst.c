#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in @array
 * Return: A pointer to the root node of the created BST or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t a, b;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (bst_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
