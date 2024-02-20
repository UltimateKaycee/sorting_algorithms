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
	int zero = 0, minus_one = -1, moon = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (moon >= minus_one)
	{
		minus_one++;
		while (head->next && zero != moon)
		{
			if (head->minus_one > head->next->minus_one)
			{
				aux = head;
			       _swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			zero++;
			head = head->next;
		}

		if (minus_one == 0)
			moon = zero;
		moon--;
		while (head->prev && zero >= minus_one)
		{
			if (head->minus_one < head->prev->minus_one)
			{
				aux = head->prev;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			zero--;
			head = head->prev;
		}
	}
}
