#include "binary_trees.h"

/**
 * binary_tree_delete -  A function that deletes an entire binary tree
 * @tree: the pointer to the root node if the tree to delete
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	recursive_delete(tree);
}


/**
 * recursive_delete - This function recursively deletes a node
 * from a binary tree
 * @node: the pointer of the node to delete
 * Return: void
 */
void recursive_delete(binary_tree_t *node)
{
	if (node == NULL)
		return;
	if (node->right == NULL && node->left == NULL)
	{
		free(node);
		return;
	}
	/* go to the left side */
	recursive_delete(node->left);
	/* go to the right side */
	recursive_delete(node->right);
	/* delete parent node */
	free(node);
	return;
}
