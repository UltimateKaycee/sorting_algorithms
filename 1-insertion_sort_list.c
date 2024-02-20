#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Function to sort doubly linked list of int in
 * ascending with insertion sort algo
 *
 * @list: doubly-linked list
 * Return: none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *ven;

	if (!list)
		return;

	ptr = *list;

	while (ptr)
	{
		while (ptr->next && (ptr->n > ptr->next->n))
		{
			ven = ptr->next;
			ptr->next = ven->next;
			ven->prev = ptr->prev;

			if (ptr->prev)
				ptr->prev->next = ven;

			if (ven->next)
				ven->next->prev = ptr;

			ptr->prev = ven;
			ven->next = ptr;

			if (ven->prev)
				ptr = ven->prev;
			else
				*list = ven;

			print_list(*list);
		}
		ptr = ptr->next;
	}
}
