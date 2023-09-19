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
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: size of array.
 * Return: index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursion - recursive function to perform quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: size of array.
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	int Lomuto;

	if (low < high)
	{
		Lomuto = partition(array, low, high, size);

		quicksort_recursion(array, low, Lomuto - 1, size);
		quicksort_recursion(array, Lomuto + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array in ascending order
 * using the Quick sort algorithm.
 * @array: Pointer to the array.
 * @size:  Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort_recursion(array, 0, size - 1, size);
}
