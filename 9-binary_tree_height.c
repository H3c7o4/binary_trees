#include "binary_trees.h"

size_t check(const binary_tree_t *node, size_t height);
/**
 * binary_tree_height - A function that measures the height
 * of a binary tree
 * @tree: the pointer to the root of the tree
 * Return: if tree is NULL rerturn 0, else return the height of the
 * tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check(tree, 0));
}


/**
 * check - A function that counts the nodes
 * of a binary tree
 * @node: the pointer to the parent node
 * @height: the pointer to the height of the tree
 * Return: the height of the binary tree
 */
size_t check(const binary_tree_t *node, size_t height)
{
	size_t new_height, left_height, right_height;

	new_height = 0;
	left_height = 0;
	right_height = 0;
	if (node->left == NULL && node->right == NULL)
	{
		return (height);
	}
	new_height = height + 1;
	/* check left */
	if (node->left != NULL)
		left_height = check(node->left, new_height);
	/* check right */
	if (node->right != NULL)
		right_height = check(node->right, new_height);
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}
