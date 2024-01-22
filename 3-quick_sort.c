#include "sort.h"

/**
 * swap_ints - Exchange the values of two integers in an array.
 * @a: Pointer to the first integer to be swapped.
 * @b: Pointer to the second integer to be swapped.
 */
:
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Rearrange a subset of an array of integer
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to be ordered.
 * @right: Ending index of the subset to be ordered.
 * Return: The final partition index.
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
 * lomuto_sort - Recursively implement the quicksort algorithm on an array.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 * @left: Starting index of the array partition to be ordered.
 * @right: Ending index of the array partition to be ordered.
 * Description: Uses the Lomuto partition scheme.
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
 * quick_sort - Applies the quicksort algorithm
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 * Description: Uses the Lomuto partition scheme.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
