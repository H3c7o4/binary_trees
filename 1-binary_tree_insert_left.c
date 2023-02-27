#include "binary_trees.h"

/**
 * binary_tree_insert_left - A function that inserts a node as
 * the left-child of another node
 * @parent: the pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: A pointer to the created node or NULL if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left;

	if (parent == NULL)
		return (NULL);
	left = binary_tree_node(parent, value);
	if (left == NULL)
		return (NULL);
	if (parent->left == NULL)
		parent->left = left;
	else
	{
		left->left = parent->left;
		(parent->left)->parent = left;
		parent->left = left;
	}
	return (left);
}
