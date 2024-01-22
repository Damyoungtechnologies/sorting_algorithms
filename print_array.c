#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	if (array == NULL || size == 0)
	{
		printf("Invalid array or size\n");
		return;
	}

	printf("%d", array[0]);

	for (size_t i = 1; i < size; ++i)
	{
		printf(", %d", array[i]);
	}

	printf("\n");
}
