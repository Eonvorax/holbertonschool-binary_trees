#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
	{
		return (NULL);
	}
	node = binary_tree_node(parent, value);
	if (node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		node->left = parent->left;
		node->left->parent = node;
	}
	parent->left = node;
	node->parent = parent;
	return (node);
}
