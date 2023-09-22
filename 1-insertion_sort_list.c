#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 * @list: doubly linked list of integers.
 * Return: (void)
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *backward, *prevBackward;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		backward = current;
		while (backward->prev != NULL)
		{
			prevBackward = backward->prev;
			if (backward->n < prevBackward->n)
			{
				prevBackward->next = backward->next;
				if (backward->next != NULL)
				{
					backward->next->prev = prevBackward;
				}
				backward->next = prevBackward;
				backward->prev = prevBackward->prev;
				if (backward->prev == NULL)
				{
					*list = backward;
				}
				else
				{
					prevBackward->prev->next = backward;
				}
				prevBackward->prev = backward;
				print_list(*list);
			}
			else
				break;
		}
		current = current->next;
	}
}
