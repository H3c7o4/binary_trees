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
	if (tree->left != NULL)
		left_height = count(tree->left, 0);
	if (tree->right != NULL)
		right_height = count(tree->right, 0);
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}


/**
 * count - A function that counts the nodes
 * of a binary tree
 * @node: the pointer to the parent node
 * @height: the pointer to the height of the tree
 * Return: size_t
 */
size_t count(const binary_tree_t *node, size_t height)
{
	size_t new_height;

	new_height = height + 1;
	if (node->left == NULL && node->right == NULL)
		return (new_height);
	if (node->left != NULL)
		if ((node->left)->left == NULL && (node->left)->right == NULL)
			count(node->left, new_height);
	if (node->right != NULL)
		if ((node->right)->left == NULL && (node->right)->right == NULL)
			count(node->right, new_height);
	return (new_height + 1);
}
