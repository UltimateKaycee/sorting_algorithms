#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Function to print array of int
 *
 * @array: The Array
 * @size: Num of elements in Array
 */
void print_array(const int *array, size_t size)
{
    size_t run;

    run = 0;
    while (array && run < size)
    {
        if (run > 0)
            printf(", ");
        printf("%d", array[run]);
        ++run;
    }
    printf("\n");
}
