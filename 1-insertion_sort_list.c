#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 * @list: doubly linked list of integers.
 * Return: (void)
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap, *previous;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		swap = current;
		while (swap->prev && swap->n < swap->prev->n)
		{
			previous = swap->prev;
			if (swap->next)
				swap->next->prev = previous;
			if (previous->prev)
				previous->prev->next = swap;
			else
				*list = swap;

			previous->next = swap->next;
			swap->prev = previous->prev;
			swap->next = previous;
			previous->prev = swap;

			print_list(*list);
		}
		current = current->next;
	}
}
