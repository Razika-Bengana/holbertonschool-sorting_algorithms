#include "sort.h"
/**
 * swap_backward -swap two nodes right left position
 * @j: list
 *
 */
void swap_backward(listint_t *j)
{
	listint_t *tmp, *head;

	while (j->prev != NULL)
	{
		if (j->n < j->prev->n)
		{
			tmp = j->prev->prev;
			j->prev->next = j->next;
			j->next = j->prev;
			j->prev->prev = j;
			j->prev = tmp;
			j->next->next->prev = j->next;
			if (tmp != NULL)
				tmp->next = j;
			head = j;
			while (head->prev != NULL)
				head = head->prev;
			print_list(head);
		}
		else
			j = j->prev;
	}
}
/**
 * swap_forward -swap two nodes left rigth position
 * @j: list
 *
 */
void swap_forward(listint_t *j)
{
	listint_t *tmp, *head;

	tmp = j->prev;

	if (tmp != NULL)
	{
		tmp->next = j->next;
		j->next->prev = tmp;
	}
	else
		j->next->prev = NULL;
	j->prev = j->next;
	if (j->next->next != NULL)
	{
		j->next = j->next->next;
		j->prev->next = j;
		j->next->prev = j;
	}
	else
	{
		j->next->next = j;
		j->next = NULL;
	}
	head = j;
	while (head->prev != NULL)
		head = head->prev;
	print_list(head);
	swap_backward(j->prev);
}
/**
 * insertion_sort_list -sort a doubly linked list with insert algorithm
 * @list: list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *j;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;
	j = *list;

	while (j->next != NULL)
	{
		if (j->n > j->next->n)
		{
			swap_forward(j);
		}
		else
			j = j->next;
	}
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
