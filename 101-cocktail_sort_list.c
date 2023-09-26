#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail Shaker Sort algorithm.
 *
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *left = *list, *right = NULL, *temp = NULL;
 
    while (swapped) {
        swapped = 0;
        while (left->next != right) {
            if (left->n > left->next->n) {
                temp = left->next;
                if (left->prev)
                    left->prev->next = temp;
                else
                    *list = temp;
                temp->prev = left->prev;
                left->prev = temp;
                left->next = temp->next;
                if (temp->next)
                    temp->next->prev = left;
                temp->next = left;
                swapped = 1;
                print_list(*list);
            }
            else
                left = left->next;
        }
        if (!swapped)
            break;
        swapped = 0;
        right = left;
        while (right && right != (*list)->prev) {
            if (right->n < right->prev->n) {
                temp = right->prev;
                if (temp->prev)
                    temp->prev->next = right;
                else
                    *list = right;
                right->prev = temp->prev;
                temp->prev = right;
                temp->next = right->next;
                if (right->next)
                    right->next->prev = temp;
                right->next = temp;
                swapped = 1;
                print_list(*list);
            }
            else
                right = right->prev;
        }
    }
}
