#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 * Return: a pointer to the uncle node or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node)
	{
		if (node->parent)
		{
			if (node->parent->parent)
			{
				if (node->parent->parent->left == node->parent)
					return (node->parent->parent->right);
				if (node->parent->parent->right == node->parent)
					return (node->parent->parent->left);
			}
			return (NULL);
		}
		return (NULL);
	}
	return (NULL);
}
