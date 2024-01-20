#include "sort.h"

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
/**
 * insertion_sort_list - sorts a list in ascending order using insertion sort
 *
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *next, *current;

	if (list == NULL || *list == NULL  || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current; current = next)
	{
		next = current->next;
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			swap_nodes(list, &prev, current);
			print_list((const listint_t *)*list);
		}
	}

}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 *
 * @h: head of the list
 * @n1: pointer to a node
 * @n2: pointer to another node
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
