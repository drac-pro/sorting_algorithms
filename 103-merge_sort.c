#include "sort.h"

void merge_recursion(int *array, int *buffer, size_t start, size_t end);
void merge_subarrays(int *array, int *buffer, size_t start, size_t mid,
		size_t end);
/**
 * merge_sort - sorts an array using top-dowb=n merge sort
 *
 * @array: the array
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	merge_recursion(array, buffer, 0, size);
	free(buffer);
}

/**
 * merge_recursion - sort sub array throug resursive calls
 *
 * @array: the array to be sorted
 * @buffer: a buffer to temporaly store the sorted array
 * @start: start index of the sub array
 * @end: end index of the sub array
 */
void merge_recursion(int *array, int *buffer, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		merge_recursion(array, buffer, start, mid);
		merge_recursion(array, buffer, mid, end);
		merge_subarrays(array, buffer, start, mid, end);
	}
}

/**
 * merge_subarrays - merge sorted sub arrays together
 *
 * @array: array to merge
 * @buffer: temporal array
 * @start: front index of the array
 * @mid: middle index
 * @end: back index of the array
 */
void merge_subarrays(int *array, int *buffer, size_t start, size_t mid,
		size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		buffer[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		buffer[k++] = array[i];
	for (; j < end; j++)
		buffer[k++] = array[j];
	for (i = start, k = 0; i < end; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
