#include "sort.h"

void swap_nodes(listint_t **h, listint_t *n1, listint_t *n2);
/**
 * cocktail_sort_list - sort a doubly linked list using cocktail sort
 *
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *ub = NULL, *lb = *list;
	int swapped = 1;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		current = lb;
		if (lb == ub)
			break;
		while (current->next != ub)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		ub = current;
		if (!swapped)
			break;
		swapped = 0;
		current = ub->prev;
		while (current && current->prev && current->prev != lb->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		lb = lb->next;
		current = lb;
	}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 *
 * @list: head of the list
 * @n1: pointer to a node
 * @n2: pointer to another node
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*list = n2;
	if (n2->next != NULL)
		n2->next->prev = n1;
	n2->prev = n1->prev;
	n1->next = n2->next;
	n2->next = n1;
	n1->prev = n2;

	/*current = node2;*/
}
