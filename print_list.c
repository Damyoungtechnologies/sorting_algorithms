#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	if (list == NULL)
	{
		printf("\n");
		return;
	}

	printf("%d", list->n);
	list = list->next;

	while (list)
	{
		printf(", %d", list->n);
		list = list->next;
	}

	printf("\n");
}
