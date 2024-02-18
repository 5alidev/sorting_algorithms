#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 *
 * Return: Nothing (void)
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp, swapped = 0;

	if (array == NULL || size < 2)
		return;
	do {
		swapped = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		i++;
	} while (swapped == 1);
}
