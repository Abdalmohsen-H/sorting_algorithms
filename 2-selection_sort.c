#include <stddef.h>
#include "sort.h"
/**
 * selection_sort - sort array using selection
 * sort algo. from the smallest numbers till
 * the biggest (in ascending order)
 * @array: input unsorted array
 * @size: array size(or array length)
 */
void selection_sort(int *array, size_t size)
{
	size_t idx, q, minidx;

	for (idx = 1; idx < size; idx++)
	{
		minidx = idx - 1;
		for (q = idx - 1; q < size; q++)
		{
			if (array[minidx] > array[q])
			{
				swap(&array[minidx], &array[q]);
				/* Next line just to visualize changes, You could comment it*/
				print_array(array, size);
			}
		}
	}
}
/**
 * swap - swap 2 values
 *
 * @frst: pointer to first value
 * @scnd: pointer to second value
 */
void swap(int *frst, int *scnd)
{
	int tmp = *frst;

	*frst = *scnd;
	*scnd = tmp;
}
