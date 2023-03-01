#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it is full, 0 if tree is NULL.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int rb1 = 0;
	int rb2 = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return(1);

	rb1 = binary_tree_is_full(tree->left);
	rb2 = binary_tree_is_full(tree->right);

	if (rb1 && rb2)
		return (1);

	return (0);
}
