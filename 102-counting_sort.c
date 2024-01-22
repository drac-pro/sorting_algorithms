#include "sort.h"

/**
 * counting_sort - sorts an array ussing counting sort
 *
 * @array: the array
 * @size: sie of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *sorted, i;
	size_t z;

	if (!array || size < 2)
		return;
	max = array[0];
	for (z = 1; z < size; z++)
		if (array[z] > max)
			max = array[z];
	count = malloc(sizeof(size_t) * (max + 1));
	sorted = malloc(sizeof(int) * size);
	if (!count || !sorted)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (z = 0; z < size; z++)
		count[array[z]] += 1;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = size - 1; i >= 0; i--)
		sorted[--count[array[i]]] = array[i];
	for (z = 0; z < size; z++)
		array[z] = sorted[z];
	free(count);
	free(sorted);
}
