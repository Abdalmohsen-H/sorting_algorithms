#include <stddef.h>
#include "sort.h"
/**
 * quick_sort_hoare - quick_sort via
 * hoare partition scheme
 * @array: input unsorted array
 * @size: array size(or array length)
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (size > 1 && array != NULL)
		hoare_quick_sort(array, low, high, size);
}
/**
 * hoare_quick_sort - start quick sort via
 * hoare partition scheme
 * @array: input unsorted array
 * @low: first index in array or partition of array
 * @high: last index in in array or partition of array
 * @size : size of whole actual array
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high <= low || low < 0 || high < 0)
		return;
	pivot = hoare_partition(array, low, high, size);
	hoare_quick_sort(array, low, pivot, size);
	hoare_quick_sort(array, pivot + 1, high, size);
}
/**
 * hoare_partition - create partations on input array
 * via Lomuto partition scheme
 * @array: input unsorted array
 * @low: first index in partition of array
 * @high: last index in partition of array
 * @size : size of whole actual array
 * Return: new pivot after making the partitions
 */
size_t hoare_partition(int *array, int low, int high, size_t size)
{int pivot_indx, leftidx, rightidx;
	/* this method select the middle index as pivot*/
	pivot_indx = ((high - low) / 2) + low;
	leftidx = low - 1;
	rightidx = high + 1;
	while (1)
	{
		do {/*increment till find elem on wrong side of pivot*/
			leftidx++;
		} while (array[leftidx] < array[pivot_indx]);
		do {/*decrement till find elem on wrong side of pivot*/
			rightidx--;
		} while (array[rightidx] > array[pivot_indx]);

		/*If the indices crossed, return rightidx*/
		if (leftidx >= rightidx)
			return (rightidx);

		swap(&array[leftidx], &array[rightidx]);
		/* next line just to visualize not req*/
		print_array(array, size);
	}
	return (high);
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
