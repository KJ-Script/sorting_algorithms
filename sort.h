#ifndef SORTING_ALGORITHMS_SORT_H
#define SORTING_ALGORITHMS_SORT_H

#include "stddef.h"

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap_array(int *array, size_t i, size_t j);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void quick_sorter(int *array, int lo, int hi, int size);
int partition(int *array, int lo, int hi, int size);
listint_t *get_head(listint_t *list);

int are_they_neighbours(listint_t *A, listint_t *B);
void refresh_outer_pointers(listint_t *A);
void swap(listint_t *A, listint_t *B);

#endif /* SORTING_ALGORITHMS_SORT_H */
