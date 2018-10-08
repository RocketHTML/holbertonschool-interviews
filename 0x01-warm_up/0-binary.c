#include "search_algos.h"

/**
 * binary_search - find index of target element
 * @array: array to search
 * @size: size of array
 * @value: value to find
 *
 * Return: index of match, or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t L = 0;
	size_t R = size - 1;
	size_t m;
	size_t i;
	char *delim = "";

	if (array == NULL)
		return (-1);

	while (L < R)
	{
		printf("Searching in array: ");
		for (i = L; i <= R; i++)
		{
			printf("%s", delim);
			printf("%d", array[i]);
			delim = ", ";
		}
		printf("\n");
		delim = "";
		sleep(1);
		m = (L + R) / 2;
		if (array[m] < value)
		{
			L = m + 1;
		}
		else if (array[m] > value)
		{
			R = m - 1;
		}
		else
		{
			return (m);
		}
	}
	return (-1);
}
