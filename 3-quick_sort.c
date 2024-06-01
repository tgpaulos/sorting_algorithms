#include "sort.h"

/**
 * lomuto_partition - Partitions an array for the quick sort algorithm
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 *
 * Description: This function partitions the array into two sub-arrays, where
 *              elements less than or equal to the pivot are on the left,
 *              and elements greater than the pivot are on the right.
 *
 * Return: The index of the pivot element after partitioning.
 */

int lomuto_partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int pivot_index = low;
	int i, temp;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (pivot_index != i)
			{
				temp = array[pivot_index];
				array[pivot_index] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			pivot_index++;
		}
	}

	if (pivot_index != high)
	{
		temp = array[pivot_index];
		array[pivot_index] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (pivot_index);
}

/**
 * quickSort - Recursively sorts an array using the quick sort algorithm
 *
 * @array: The array to be sorted
 * @low: The starting index of the sub-array to be sorted
 * @high: The ending index of the sub-array to be sorted
 * @size: Number of elements in @array
 *
 * Description: This function implements the quick sort algorithm to sort
 *              a sub-array of the given array.
 */

void quickSort(int *array, int low, int high, int size)
{
	if (low < high)
	{
		size_t pivot = lomuto_partition(array, low, high, size);

		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: This function sorts the elements of the given array in
 *              ascending order using the quick sort algorithm.
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
