#include "binary_trees.h"

/**
 * binary_tree_insert_right - A function that inserts a node as
 * the left-child of another node
 * @parent: the pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: A pointer to the created node or NULL if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rightt;

	if (parent == NULL)
		return (NULL);

	right = binary_tree_node(parent, value);
	if (right == NULL)
		return (NULL);
	if (parent->right == NULL)
		parent->right = right;
	else
	{
		right->right = parent->right;
		(parent->right)->parent = right;
		parent->right = right;
	}
	return (right);
}
