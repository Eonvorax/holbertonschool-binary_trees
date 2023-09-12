#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (MAX(binary_tree_height(tree->left),
	 binary_tree_height(tree->right)) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect (full branches)
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);

	return (binary_tree_is_perfect(tree->left) &&
	 binary_tree_is_perfect(tree->right));
}
