#include "sort.h"

/**
 * swap_ints - Exchange two integers within an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - Arrange a portion of an integer array
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to organize.
 * @right: The ending index of the subset to organize.
 *
 * Return: The ultimate partition index.
 */


int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}
/**
 * lomuto_sort - Recursively implement the quicksort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array partition to arrange.
 * @right: The ending index of the array partition to arrange.
 * Description: Applies the Lomuto partition scheme for sorting.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}
/**
 * quick_sort - Arrange an array of integers in ascending order
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * Description: Applies the Lomuto partition scheme.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
