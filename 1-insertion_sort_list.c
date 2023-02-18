#include "sort.h"

/**
* insertion_sort_list - function that sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
* @list: double linked list to sort
* Return: nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	/* @if checks for null*/
	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while(node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
* *swap_node - swap a node to its previous one
* @node: a node
* @list: node list
* Return: pointer to the node
*/

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
