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
	return (MAX(binary_tree_height(tree->left), binary_tree_height(tree->right))
	 + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: height of left branch minus height of right branch
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (1);
	}
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect (full branches)
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if not
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (binary_tree_balance(tree) == 0 && binary_tree_is_full(tree) == 1);
}