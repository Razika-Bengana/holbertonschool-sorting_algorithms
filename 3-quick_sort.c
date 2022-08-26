#include "sort.h"

/**
 * swap - swap two numbers
 * @x: an integer
 * @y: an integer
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - function that finds the position of the array
 * @array: the array
 * @low: the lower array
 * @high: the higher array
 * @size: the size of the array
 * Return: i + 1
 */

int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (j != i)
				print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);

	if (high != (i + 1))
		print_array(array, size);

	return (i + 1);
}

/**
 * quickSort - function that sort the divided array
 * @array: the array
 * @low: the lower array
 * @high: the highest array
 * @size: the size of the array
 * Retrun: the result
 */

void quickSort(int array[], int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array
 * @size: the size of the array
 * Return: the result
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;

	quickSort(array, 0, (size - 1), size);
}
