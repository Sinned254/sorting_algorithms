#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @array: The array containing the integers
 * @a: Index of the first integer to swap
 * @b: Index of the second integer to swap
 */
void swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The new pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	size_t k, m;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
			if (i != j)
			{
				for (k = 0; k < size; k++)
					printf("%d%s", array[k], k < size - 1 ? ", " : "\n");
			}
		}
	}
	swap(array, i + 1, high);
	if (i + 1 != high)
	{
		for (m = 0; m < size; m++)
			printf("%d%s", array[m], m < size - 1 ? ", " : "\n");
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts an array using Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
