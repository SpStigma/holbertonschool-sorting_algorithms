#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size:  Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min_index = 0;
	int temp;

	if (array == 0 || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		print_array(array, size);
	}
}
