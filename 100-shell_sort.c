#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    if (!array || size < 2)
        return;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        gap /= 3;
        /* Print the array after each decrease in interval */
        print_array(array, size);
    }
}
