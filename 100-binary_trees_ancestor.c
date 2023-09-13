#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth from
 *
 * Return: depth of the node in the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
	{
		return (0);
	}
	return (binary_tree_depth(tree->parent) + 1);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, NULL if none found
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *) first);
	}
	if (binary_tree_depth(first) > binary_tree_depth(second))
	{
		return (binary_trees_ancestor(first->parent, second));
	}
	if (binary_tree_depth(first) < binary_tree_depth(second))
	{
		return (binary_trees_ancestor(first, second->parent));
	}
	return (binary_trees_ancestor(first->parent, second->parent));
}
