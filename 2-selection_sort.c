#include <stdio.h>
#include "sort.h"

/**
 * find_min - function that returns minimum index
 * @a: pointer to array
 * @size: size of array
 * @index: index to start from
 *
 * Return: min index
 */
int find_min(int *a, size_t size, size_t index)
{
	int min = a[index];
	size_t i;

	for (i = index + 1; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			index = i;
		}
	}
	return (index);
}

/**
 * selection_sort - selection sort alogarithm
 * @array: array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, swap, index;

	for (i = 0; i < size - 1 && array && size; i++)
	{
		index = find_min(array, size, i);

		if (index != i)
		{
			swap = array[i];
			array[i] = array[index];
			array[index] = swap;
		}
		print_array(array, size);
	}
}

