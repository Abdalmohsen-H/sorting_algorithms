#include <stddef.h>
#include "sort.h"
/**
 * quick_sort - quick_sort via
 * Lomuto partition scheme
 * @array: input unsorted array
 * @size: array size(or array length)
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (high > low && array)/* size > 1 && array*/
		main_quick_sort(array, low, high, size);
	else
		return
}
/**
 * main_quick_sort - start quick sort via
 * Lomuto partition scheme
 * @array: input unsorted array
 * @low: first index in array or partition of array
 * @high: last index in in array or partition of array
 * @size : size of whole actual array
 */
void main_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high <= low)
		return;
	pivot = partition(array, low, high, size);
	main_quick_sort(array, low, pivot - 1, size);
	main_quick_sort(array, pivot + 1, high, size);
}
/**
 * partition - create partations on input array
 * via Lomuto partition scheme
 * @array: input unsorted array
 * @low: first index in partition of array
 * @high: last index in partition of array
 * @size : size of whole actual array
 * Return: new pivot after making the partitions
 */
size_t partition(int *array, int low, int high, size_t size)
{int pivot_indx, tmp_nw_pivot_idx = low - 1, j;

	if (high > low)
	{
		pivot_indx = high;/* this method select the last index as pivot*/
		for (j = low; j < pivot_indx; j++)
		{
			if (array[j] < array[pivot_indx])
			{
				tmp_nw_pivot_idx++;
				if (tmp_nw_pivot_idx != j)/*avoid swapping same element*/
				{
					swap(&array[tmp_nw_pivot_idx], &array[j]);
					/* next line just to visualize not req*/
					print_array(array, size);
				}
			}
		}
		/* important increment tmp_pivot first*/
		/*this should be outside above loop*/
		tmp_nw_pivot_idx++;
		if (tmp_nw_pivot_idx != pivot_indx)/*avoid swapping same element*/
		{swap(&array[tmp_nw_pivot_idx], &array[pivot_indx]);
			print_array(array, size);
		}
		return (tmp_nw_pivot_idx);/*return new pivot index*/
	}
	return (high);/*if it only one element in partiton*/
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
