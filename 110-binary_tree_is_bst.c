#include "binary_trees.h"


int check_side(const binary_tree_t *tree, char side, int root);

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
	int ch;

	ch = 0;

	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->parent == NULL)
	{
		if (tree->left != NULL)
			if ((tree->left)->n > tree->n)
				return (0);
		if (tree->right != NULL)
			if ((tree->right)->n < tree->n)
				return (0);
	}
	else
	{
		ch = check_side(tree, 'R', root);
		if (ch == 0)
			return (0);
		ch = check_side(tree, 'L', root);
		if (ch == 0)
			return (0);
	}
	if (tree->left != NULL && tree->right != NULL)
		if ((tree->left)->n == (tree->right)->n)
			return (0);
	ch = is_bst(tree->left, tree->n);
	if (ch == 0)
		return (0);
	ch = is_bst(tree->right, tree->n);
	if (ch == 0)
		return (0);
	return (1);
}

/**
 * check_side - A function that checks the left side of the
 * binary tree to see if a binary tree is a BST
 * @tree: the pointer to the root of the tree
 * @side: "L" or "R" to show which side to check R is right
 * and L is left
 * @root: the data stored in the root of the tree
 * Return: 0 if the side is not a BST
 */
int check_side(const binary_tree_t *tree, char side, int root)
{
	if (side == 'R')
	{
		if (tree->n > root) /*right side*/
		{
			if (tree->left != NULL && ((tree->left)->n > tree->n
						|| (tree->left)->n < root))
				return (0);
			if (tree->right != NULL && ((tree->right)->n < tree->n
						|| (tree->right)->n < root))
				return (0);
		}
	}
	else if (side == 'L')
	{
		if (tree->n < root) /*left side*/
		{
			if (tree->left != NULL && ((tree->left)->n > tree->n
						|| (tree->left)->n > root))
				return (0);
			if (tree->right != NULL && ((tree->right)->n < tree->n
						|| (tree->right)->n > root))
				return (0);
		}
	}
	return (1);
}
