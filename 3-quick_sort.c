#include "sort.h"

void swap(int *a, int *b);
void quicksort(int *array, size_t size, int low, int high);
int partition(int *array, size_t size, int low, int high);
/**
 * quick_sort - sorts an array in ascending order using quick sort
 *
 * @array: the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}

/**
 * quicksort - quick_sort recursize function
 *
 * @array: the array
 * @size: size of the array
 * @low: lowerbound of the array
 * @high: upperbound of the array
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quicksort(array, size, low, pivot - 1);
		quicksort(array, size, pivot + 1, high);
	}
}

/**
 * partition - quick_sort partitioning function
 *
 * @array: the array
 * @size: size of the array
 * @low: lowerbound of the array
 * @high: upperbound of the arraywhich will be used as pivot()
 *
 * Return: the correct pivot position
 */
int partition(int *array, size_t size, int low, int high)
{
	int i, j;

	for (j = i = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * swap - swaps two integers
 *
 * @a: pointer to first int
 * @b: pointer to second int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
