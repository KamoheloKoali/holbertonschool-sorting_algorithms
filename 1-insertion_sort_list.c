#include "sort.h"

/**
 * sortedInsert - insert a new node in a sorted way
 * @head_ref: pointer to header node
 * @newNode: pointer to current node
 */

void sortedInsert(listint_t **list, listint_t **head_ref, listint_t *newNode)
{
	listint_t *current;

	if (*head_ref == NULL)
		*head_ref = newNode;

	else if ((*head_ref)->n >= newNode->n)
	{
		newNode->next = *head_ref;
		newNode->next->prev = newNode;
		*head_ref = newNode;

	} else
	{
		current = *head_ref;

		while (current->next != NULL && current->next->n < newNode->n)
			current = current->next;

		newNode->next = current->next;
		
		if (current->next != NULL)
			newNode->next->prev = newNode;
		current->next = newNode;
		newNode->prev = current;
	}
	print_list(*list);
}

/**
 * i_sort - sort a doubly linked list
 * @head_ref: pointer to pointer
 */

void i_sort(listint_t **list, listint_t **head_ref)
{
	listint_t *sorted = NULL, *current = *head_ref, *next;

	while (current != NULL)
	{
		next = current->next;
		current->prev = current->next = NULL;
		sortedInsert(list, &sorted, current);
		current = next;
	}
	*head_ref = sorted;
}

/**
 * insertion_sort_list - sort list in ascending order
 * @list: pointer to first node in list
 */

void insertion_sort_list(listint_t **list)
{
	i_sort(list, list);
}
