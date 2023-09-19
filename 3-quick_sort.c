#include "sort.h"
/**
 * swap - function to swap two elements.
 * @i: Pointer to the first integer.
 * @j: Pointer to the second integer.
 */
void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}
/**
 * partition - partitions an array using Lomuto scheme.
 * @array: Pointer to the array.
 * @l: Starting index of the partition.
 * @r: Ending index of the partition.
 * @size: size of array.
 * Return: index of the pivot element.
 */
int partition(int *array, int l, int r, size_t size)
{
	int pivot = array[r];
	int i = l;

	for (int j = l; j < r; ++j)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			++i;
		}
	}
	swap(&array[i], &array[r]);
	print_array(array, size);
	return (i);
}
/**
 * quicksort_recursion - recursive function to perform quick sort.
 * @array: Pointer to the array.
 * @l: Starting index of the partition.
 * @r: Ending index of the partition.
 * @size: size of array.
 */

void quicksort_recursion(int *array, int l, int r, size_t size)
{
	if (l >= r)
		return;

	int i = partition(array, l, r, size);

	quicksort_recursion(array, l, i - 1, size);
	quicksort_recursion(array, i + 1, r, size);
}

/**
 * quick_sort - sorts an array in ascending order
 * using the Quick sort algorithm.
 * @array: Pointer to the array.
 * @size:  Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
	return;

	quicksort_recursion(array, 0, size - 1, size);
}


