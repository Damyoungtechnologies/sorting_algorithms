#include "sort.h"

/**
 * swap_ints - exchanges the values of two integers in an array
 * @a: pointer to the first integer to be swapped
 * @b: pointer to the second integer to be swapped
 * Return: void, as there is no return value
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * bubble_sort - performs a bubble sort on an array of int in ascending order
 * @array: pointer to the array of integers to be sorted
 * @size: size of the array
 * Return: void, as there is no return value
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
