#include "sort.h"

/**
 * _swap - Function to swap 2 nodes of dl list
 *
 * @node: node base
 * @list: dl list head
 *
 * Return: None
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *make_one = *node, *make_two, *make_three;


	if (!(*node)->prev)
		*list = (*node)->next;

	make_one = make_three = *node;
	make_two = make_one->next;

	make_one->next = make_two->next;
	make_three = make_one->prev;
	make_one->prev = make_two;
	make_two->next = make_one;
	make_two->prev = make_three;

	if (make_two->prev)
		make_two->prev->next = make_two;


	if (make_one->next)
		make_one->next->prev = make_one;

	*node = make_two;

}
/**
 * cocktail_sort_list - Function to sort dl list
 * of int
 *
 * @list: head of double linked list)
 *
 * Return: None
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       _swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			c++;
			head = head->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			c--;
			head = head->prev;
		}
	}
}
