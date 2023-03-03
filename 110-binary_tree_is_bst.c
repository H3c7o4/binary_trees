#include "binary_trees.h"


/**
 * binary_tree_is_bst - A function that checks if a binary tree is
 * a valid Binary search tree
 * @tree: the pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree));
}

/**
 * is_bst - A function that checks if a binary tree is
 * a valid Binary search tree
 * @tree: the pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST and 0 otherwise
 * if tree is NULL return 1
 */
int is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && (is_max(tree->left) > tree->n))
		return (0);
	if (tree->right != NULL && (is_min(tree->right) < tree->n))
		return (0);
	if (!is_bst(tree->left) || !is_bst(tree->right))
		return (0);
	return (1);
}


/**
 * is_max - A function that returns the biggest number
 * in a binary tree
 * @tree: the pointer to the root of the tree
 * Return: the biggest number
 */
int is_max(const binary_tree_t *tree)
{
	int left, right, biggest;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (tree->n);

	left = is_max(tree->left);
	right = is_max(tree->right);

	if (left > right)
		biggest = left;
	else
		biggest = right;
	if (biggest > tree->n)
		return (biggest);
	return (tree->n);
}


/**
 * is_min - A function that returns the smallest number in
 * a binary tree
 * @tree: the pointer to the root of the tree
 * Return: the smallest number in the tree
 */
int is_min(const binary_tree_t *tree)
{
	int left, right, smallest;

	if (tree == NULL)
		return (1000000);
	if (tree->left == NULL && tree->right == NULL)
		return (tree->n);
	left = is_min(tree->left);
	right = is_min(tree->right);
	if (left < right)
		smallest = left;
	else
		smallest = right;
	if (smallest < tree->n)
		return (smallest);
	return (tree->n);
}
