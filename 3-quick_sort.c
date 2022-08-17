#include "sort.h"

/**
 * quick_sort - sorts @array by calling quick_sorter
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sorter(array, 0, (int) size - 1, (int) size);
}

/**
 * quick_sorter - sorts @array using quick sort's Lomuto partition scheme and
 * prints the array each time the pivot is swapped with the end item
 * @array: array to be sorted
 * @lo: lower boundary
 * @hi: higher boundary
 * @size: size of the array, passed to partition to print the array
 *
 * Return: void
 */
void quick_sorter(int *array, int lo, int hi, int size)
{
	int pivot;

	if (lo >= hi || lo < 0)
		return;

	pivot = partition(array, lo, hi, size);

	quick_sorter(array, lo, pivot - 1, size);
	quick_sorter(array, pivot + 1, hi, size);
}

/**
 * partition - partitions @array between @lo and @hi and finds the center
 * sport for @pivot by making sure the elements beneath and beyond @i are
 * smaller and larger (or equal to) @pivot, between @lo and @hi
 * @array: array to be sorted
 * @lo: lower boundary
 * @hi: higher boundary
 * @size: size of the array, to print when @pivot has found its right place
 *
 * Return: the new position of the pivot
 */
int partition(int *array, int lo, int hi, int size)
{
	int pivot = array[hi];  /* Last element is chosen as the pivot */
	int i = lo - 1;  /* Temporary pivot index, used to find its final index */
	int j;  /* To scroll through the array */
	int c; /* To swap array elements */

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{

			i += 1; /* Move the temporary index forward */

			/**
			 * Swap the current element with the element at the temporary
			 * pivot index
			 */
			c = array[i];
			array[i] = array[j];
			array[j] = c;

		}
	}

	/**
	 * Move pivot to the correct position, between the smaller and larger
	 * elements
	 */
	i += 1;
	c = array[hi];
	array[hi] = array[i];
	array[i] = c;
	print_array(array, size);

	return (i);

}
