#include <stdio.h>
#include "sort.h"

/**
 * print_list - Function to print list of int
 *
 * @list: The list
 */
void print_list(const listint_t *list)
{
    int run;

    run = 0;
    while (list)
    {
        if (run > 0)
            printf(", ");
        printf("%d", list->n);
        ++run;
        list = list->next;
    }
    printf("\n");
}
