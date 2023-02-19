#include "sort.h"
/**
* swap - switch the positions of two elements into an array
* @array: an array
* @item1: an array element
* @item2: an array element
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;
	tmp = array[item1];

	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
* partition - lomuto partition sorting scheme implementation
* @array: array
* @first: the first array element
* @last: the last array element
* @size: size of the array
* Return: return the position of the last element sorted
*/

int partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;
	/*@for loops through pivot*/
	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
* qs - qucksort algorith
* @array: array
* @first: the first array element
* @last: the last array element
* @size: the array size
*/
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
* quick_sort - function that sorts an array of integers in
* ascending order using the Quick sort algorithm
* @array: array pointer
* @size: size of array
* Return: nothing
*/

void quick_sort(int *array, size_t size)
{
	/*@if checks for array*/
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
