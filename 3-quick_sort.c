#include "sort.h"

/**
 * partition - partitions the array
 * @array: array to be sorted
 * @start: starting index
 * @end: last index
 *
 * Return: partition index
 */

int partition(int *array, int start, int end)
{
	int partition_index, pivot, i, temp;

	pivot = array[end];
	partition_index = (start - 1);

	for (i = start; i <= end - 1; i++)
	{
		if (array[i] <= pivot)
		{
			partition_index += 1;
			temp = array[i];
			array[i] = array[partition_index];
			array[partition_index] = temp;

		}
	}
	temp = array[partition_index + 1];
	array[partition_index + 1] = array[end];
	array[end] = temp;

	return (partition_index + 1);
}

/**
 * quicknsort - recursively sorting partitions
 * @array: array of ints
 * @start: starting index
 * @end: stopping index
 */

void quicknsort(int *array, int start, int end)
{
	int idx;
	int arrsize;
	int arrelem;
	int size;

	arrsize = sizeof(array);
	arrelem = sizeof(array[0]);

	size = arrsize / arrelem;


	if (start < end)
	{
		idx = partition(array, start, end);
		quicknsort(array, start, idx - 1);
		quicknsort(array, idx + 1, end);

	}
	print_array(array, size);

}

/**
 * quick_sort - calls the quicknsort function
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size)
	{
		int start = 0;
		int end = size - 1;

		quicknsort(array, start, end);
	}
}
