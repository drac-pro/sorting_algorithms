#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using shell sort.
 *
 * @array: the array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, j;
	int temp, i;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0 && array[i + gap] < array[i]; i -= gap)
			{
				temp = array[i + gap];
				array[i + gap] = array[i];
				array[i] = temp;
			}
		}
		print_array(array, size);
	}
}
