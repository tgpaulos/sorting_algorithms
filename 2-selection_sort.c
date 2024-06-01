#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t current_index, next_index, min_index;
	int temp;

	if (!array || !size)
		return;

	for (current_index = 0; current_index < size; current_index++)
	{
		min_index = current_index;

		for (next_index = current_index + 1; next_index < size; next_index++)
		{
			if (array[next_index] < array[min_index])
				min_index = next_index;
		}

		if (array[current_index] > array[min_index])
		{
			temp = array[current_index];
			array[current_index] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
