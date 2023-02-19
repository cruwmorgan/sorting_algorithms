#include "sort.h"

/**
* swp - the positions of two elements into an array
* @array: an array
* @item1: an array element
* @item2: an array element
* Return: nothing is returned
*/

void swp(int *array, int item1, int item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
* shell_sort - function that sorts an array of integers in ascending order
* using the Shell sort algorithm, using the Knuth sequence
* @array: a pointer to an array
* @size: size of the array
* Return: nothing
*/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;
	/*@if checks for null*/
	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swp(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
