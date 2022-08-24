#include "sort.h"
/**
 * bubble_sort - Sort an array with buble sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t count, j;

	if (array == NULL || size == 0)
		return;

	for (count = 0; count < size; count++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
