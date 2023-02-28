#include "binary_trees.h"

/**
 * binary_tree_postorder - A function that goes through a binary tree
 * using post-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to the function to call for eachb node
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	if (tree->left != NULL)
		func(tree->left->n);
	binary_tree_postorder(tree->right, func);
	if (tree->right != NULL)
		func(tree->right->n);
	if (tree->parent == NULL)
		func(tree->n);
}
