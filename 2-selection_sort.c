// C program that implement a selection sort

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
 * selection_sort - function that sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: the result
 */

void selection_sort(int *array, size_t size)
{
	unsigned int a, b, min_idx;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		min_idx = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min_idx])
				min_idx = b;
		}

		/*  Swap the found minimum element with the first element,
		    and print the array */

		if (min_idx != a)
		{
			swap(&array[min_idx], &array[a]);
			print_array(array, size);
		}
	}

}
