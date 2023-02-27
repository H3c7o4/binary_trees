#include "binary_trees.h"

/**
 * binary_tree_node - A function that creates a binary tree node
 * @parent: the pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: A pointer to the binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *bTreeNode;

	bTreeNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (bTreeNode == NULL)
		return NULL;
	bTreeNode->parent = parent;
	bTreeNode->n = value;
	bTreeNode->left = NULL;
	bTreeNode->right = NULL;
	return (bTreeNode);
}
