#include "lists.h"

/**
 * check_recursively - Recursively checks if a linked list is a palindrome
 * @start: Points to the start of the list
 * @end: Points to the end of the list (updated recursively)
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int check_recursively(listint_t **start, listint_t *end)
{
    /* Base case: Reached the end of the list, it's a palindrome */
    if (end == NULL)
        return 1;

    /* Compare values at start and end pointers */
    if ((*start)->n != end->n)
        return 0;

    /* Move start pointer forward, and end pointer backward */
    *start = (*start)->next;

    /* Continue checking recursively */
    return check_recursively(start, end->next);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Points to the start of the linked list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    /* Empty list is considered a palindrome */
    if (*head == NULL)
        return 1;

    listint_t **start = head;
    listint_t *end = *head;

    /* Check recursively for palindrome */
    return check_recursively(start, end);
}
