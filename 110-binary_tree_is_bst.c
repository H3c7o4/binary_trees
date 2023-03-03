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
	return (is_bst(tree, tree->n));
}

/**
 * is_bst - A function that checks if a binary tree is
 * a valid Binary search tree
 * @tree: the pointer to the root node of the tree to check
 * @root: the data stored at the root node
 * Return: 1 if tree is a valid BST and 0 otherwise
 * if tree is NULL return 0
 */
int is_bst(const binary_tree_t *tree, int root)
{
	int check;

	check = 0;
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL)
	{
		if (tree->n > root)
		{
			if ((tree->left)->n > tree->n || (tree->left)->n < root)
				return (0);
		}
		else if (tree->n < root)
			if ((tree->left)->n > tree->n || (tree->left)->n > root)
				return (0);
	}
	if (tree->right != NULL)
	{
		if (tree->n < root)
		{
			if ((tree->right)->n < tree->n || (tree->right)->n > root)
				return (0);
		}
		else if (tree->n > root)
			if ((tree->right)->n < tree->n || (tree->right)->n < root)
				return (0);
	}
	if (tree->left != NULL)
	{
		check = is_bst(tree->left, root);
		if (check == 0)
			return (check);
	}
	if (tree->right != NULL)
	{
		check = is_bst(tree->right, root);
		if (check == 0)
			return (check);
	}
	return (1);
}
