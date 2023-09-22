#include "sort.h"


void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int swaped;

    for (i = 0; i < size - 1; i++)
    {
        swaped = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                array[j] = array[j] + array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j + 1];
                swaped = 1;
                print_array(array, size);
            }
        }
        if (!swaped)
            break;
    }
}
