#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nxt, *curr;

	if (!list || !*list || !(*list)->next)
		return;

	curr = *list;
	while (curr)
	{
		nxt = curr->next;
		while (curr->prev && curr->n < curr->prev->n)
		{
			curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;

			curr->next = curr->prev;
			curr->prev = curr->prev->prev;
			curr->next->prev = curr;

			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr;

			print_list(*list);

		}
		curr = nxt;
	}
}
