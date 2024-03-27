#include "binary_trees.h"
#include <stdlib.h>

/**
 * count_nodes - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The total number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (count_nodes(tree->left) + count_nodes(tree->right) + 1);
}

/**
 * is_complete_recursive - Recursively checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node in a complete binary tree
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
			is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count = count_nodes(tree);

	return (is_complete_recursive(tree, 0, node_count));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_left, size_right;

	if (tree == NULL)
		return (0);

	size_left = binary_tree_size(tree->left);
	size_right = binary_tree_size(tree->right);

	return (1 + size_left + size_right);
}
