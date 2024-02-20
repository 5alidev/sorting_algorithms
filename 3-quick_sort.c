#include "sort.h"

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothnig (void)
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}

/**
 * swap_values - swap two integer values
 *
 * @val_1: first value
 * @val_2: second value
 *
 * Return: Nothing (void)
 */
void swap_values(int *val_1, int *val_2)
{
	int temp;

	temp = *val_1;
	*val_1 = *val_2;
	*val_2 = temp;
}

/**
 * quick_sort_recursion - quick sort recursion
 *
 * @array: array to sort
 * @size: array size
 * @low: low index of array (0)
 * @high: high index of array (size - 1)
 *
 * Return: Nothing (void)
 */
void quick_sort_recursion(int array[], size_t size, int low, int high)
{
	size_t pivot_index;

	if (high - low > 0)
	{
		pivot_index = partition(array, size, low, high);
		quick_sort_recursion(array, size, low, pivot_index - 1);
		quick_sort_recursion(array, size, pivot_index + 1, high);
	}
}

/**
 * partition - partition to sort
 *
 * @array: array to sort
 * @size: array size
 * @low: low index of array (0)
 * @high: high index of array (size - 1)
 *
 * Return: index of last element sorted
 */
size_t partition(int array[], size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] <= *pivot)
		{
			if (i < j)
			{
				swap_values(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap_values(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}
