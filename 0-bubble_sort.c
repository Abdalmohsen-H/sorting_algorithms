#include <stddef.h>
#include "sort.h"
/**
 * bubble_sort - Entry point
 * @array: input unsorted array
 * @size: array size(or array length)
 */
void bubble_sort(int *array, size_t size)
{size_t outidx, inidx;

		if (array && size)
		{
				for (outidx = 1; outidx < size; outidx++)
				{
						for (inidx = 1; inidx < size; inidx++)
						{
								if (array[inidx - 1] > array[inidx])
								{
										swap(&array[inidx - 1], &array[inidx]);
										/* next line just to visualize you could comment it*/
										print_array(array, size);
								}
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
