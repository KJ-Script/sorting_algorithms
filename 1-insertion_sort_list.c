#include "sort.h"

/**
 * insertion_sort_list - sorts @list using the bubble sort algorithm, printing
 * the list on each swap_array
 * @list: doubly linked list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	struct listint_s *j, *store, **key = list;
	int i, shifted;

	if (!key || !(*key)->next)
	{
		return;
	}

	*key = (*key)->next;
	while (*key)
	{
		shifted = 0;
		store = *key;
		j = (*key)->prev;
		while (j)
		{
			if (j->next && store->n < j->n)
			{
				swap(j, *key);
				shifted += 1;
				print_list(get_head(*list));
			}
			j = j->prev;
		}
		for (i = -1; i < shifted; i++)
			*key = (*key)->next;
	}
	*list = get_head(store);
}

/**
 * get_head - returns the first element of the doubly linked list
 * @list: the doubly linked list
 *
 * Return: head of @list
 */
listint_t *get_head(listint_t *list)
{
	while (list->prev)
		list = list->prev;
	return (list);
}

/**
 * are_they_neighbours - checks whether @A and @B are next to eachother
 * @A: first node to be checked
 * @B: second node to be checked
 *
 * Return: 1 if @A and @B are next to each other, 0 otherwise
 */
int are_they_neighbours(listint_t *A, listint_t *B)
{
	return ((A->next == B && B->prev == A) || (A->prev == B && B->next == A));
}

/**
 * refresh_outer_pointers - makes sure that @A's previous node points to @A,
 * vice versa for the next node
 * @A: node to be refreshed
 */
void refresh_outer_pointers(listint_t *A)
{
	if (A->prev != NULL)
		A->prev->next = A;

	if (A->next != NULL)
		A->next->prev = A;
}

/**
 * swap - swaps nod @A and @B
 * @A: first node to be swapped
 * @B: first node to be swapped
 */
void swap(listint_t *A, listint_t *B)
{
	listint_t *swapper_vector[4];
	listint_t *temp;

	if (A == B)
		return;

	if (B->next == A)
	{
		temp = A;
		A = B;
		B = temp;
	}

	swapper_vector[0] = A->prev;
	swapper_vector[1] = B->prev;
	swapper_vector[2] = A->next;
	swapper_vector[3] = B->next;

	if (are_they_neighbours(A, B))
	{
		A->prev = swapper_vector[2];
		B->prev = swapper_vector[0];
		A->next = swapper_vector[3];
		B->next = swapper_vector[1];
	} else
	{
		A->prev = swapper_vector[1];
		B->prev = swapper_vector[0];
		A->next = swapper_vector[3];
		B->next = swapper_vector[2];
	}

	refresh_outer_pointers(A);
	refresh_outer_pointers(B);
}
