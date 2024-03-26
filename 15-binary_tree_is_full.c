#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If a node has no children, it is full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If a node has one child but not both, it is not full */
	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
		return (0);

	/* Recursively check if both subtrees are full */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
