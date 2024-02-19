#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: Nothing (void)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *insert, *i;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swapNodes(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swapNodes - swapp two nodes
 *
 * @headRef: ref to the head of the list
 * @node1: first node
 * @node2: second node
 *
 * Return: Nothing (void)
 */
void swapNodes(listint_t **headRef, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = (*node1);
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*headRef = node2;
	(*node1)->prev = node2;
	(*node1) = node2->prev;
}
