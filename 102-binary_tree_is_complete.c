#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Create a queue to perform level order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *)
	* binary_tree_size(tree));
	size_t front = 0, rear = 0;
	int flag = 0; /* To indicate if a non-full node is encountered */

	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* If a non-full node is encountered after a full node, return false */
		if (current == NULL)
			flag = 1;
		else
		{
			if (flag)
			{
				free(queue);
				return (0);
			}

			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	free(queue);
	return (1);
}
