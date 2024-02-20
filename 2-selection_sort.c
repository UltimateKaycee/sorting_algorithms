#include "sort.h"
/**
  * selection_sort - Function to sort array of int.
  * @array: Array
  * @size: size of Array
  */
void selection_sort(int *array, size_t size)
{
	size_t run, bail, take, ven;
	int *head;

	if (!array || size < 2)
		return;
	head = array;
	for (run = 0; run < size; run++, head++)
	{
		for (take = run, bail = run; bail < size; bail++)
			if (array[bail] < array[take])
			{
				take = bail;
			}
		if (run != take)
		{
			ven = array[take];
			array[take] = *head;
			*head = ven;
			print_array(array, size);
		}
	}
}
