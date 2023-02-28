#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height
 * of a binary tree
 * @tree: the pointer to the root of the tree
 * Return: if tree is NULL rerturn 0, else return the height of the
 * tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = 0;
	right_height = 0;
	if (tree == NULL)
		return (0);
	left_height = count_left(tree, 0);
	right_height = count_right(tree, 0);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}


/**
 * count_left - A function that counts the left nodes
 * of a binary tree
 * node: the pointer to the parent node
 * height: the pointer to the height of the tree
 * Return: size_t
 */
size_t count_left(const binary_tree_t *node, size_t height)
{
	size_t new_height;

	new_height = 0;
	if (node->left == NULL)
		return (height);
	new_height = height + 1;
	count_left(node->left, new_height);
	return (new_height);
}

/**
 * count_right - A function that counts the right nodes
 * of a binary tree
 * node: the pointer to the parent node
 * height: the pointer to the height of the tree
 * Return: size_t
 */
size_t count_right(const binary_tree_t *node, size_t height)
{
	size_t new_height;

	new_height = 0;
	if (node->right == NULL)
		return (height);
	new_height = height + 1;
	count_right(node->right, new_height);
	return (new_height);
}
