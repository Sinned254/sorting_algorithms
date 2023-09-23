#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL, *current = *list, *next;

    while (current)
    {
        next = current->next;

        if (!sorted || sorted->n >= current->n)
        {
            current->next = sorted;
            current->prev = NULL;
            if (sorted)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            listint_t *tmp = sorted;

            while (tmp->next && tmp->next->n < current->n)
                tmp = tmp->next;

            current->next = tmp->next;
            current->prev = tmp;
            if (tmp->next)
                tmp->next->prev = current;
            tmp->next = current;
        }

        current = next;
        if (current)
            current->prev = NULL;

        /* Print the entire list after each pass */
        print_list(sorted);
    }

    *list = sorted;  /* Update the head of the list */
}
