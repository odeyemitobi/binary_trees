#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	binary_tree_t *left_ancestor, *right_ancestor;

	left_ancestor = binary_trees_ancestor(first, second->left);
	right_ancestor = binary_trees_ancestor(first, second->right);

	if (left_ancestor && right_ancestor)
		return ((binary_tree_t *)second);
	else if (left_ancestor)
		return (left_ancestor);
	else
		return (right_ancestor);
}
