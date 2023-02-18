#include "sort.h"
/**
* bubble_sort - function that sorts an array of integers
* in ascending order using the Bubble sort algorithm
* @array: pointer to an array
* @size: array size
* Return: nothing is returned
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, index, tmp = 0;
	/*@if checks if size is less than 2*/
	if (size < 2)
		return;
	/*@for loops through arry*/
	for (i = 0; i < size; i++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
			}
		}

}
