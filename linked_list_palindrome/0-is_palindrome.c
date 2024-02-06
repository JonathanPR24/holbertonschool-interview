#include "lists.h"

/**
 * check_recursively - Recursively checks if a linked list is a palindrome
 * @start: Points to the current node in the first half of the list
 * @end: Points to the current node in the second half of the list (updated recursively)
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int check_recursively(listint_t **start, listint_t *end)
{
    int is_palindrome;

    /* Base case: Reached the end of the list, it's a palindrome */
    if (end == NULL)
        return 1;

    /* Check recursively for palindrome in the remaining nodes */
    is_palindrome = check_recursively(start, end->next);

    /* If previous checks failed, no need to proceed further */
    if (is_palindrome == 0)
        return 0;

    /* Compare values at start and end nodes */
    if ((*start)->n == end->n)
        is_palindrome = 1;
    else
        is_palindrome = 0;

    /* Move start pointer to the next node in the first half */
    *start = (*start)->next;

    return is_palindrome;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Points to the start of the linked list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t **start = head;
    listint_t *end = *head;

    /* An empty list is always considered a palindrome */
    if (*head == NULL)
        return 1;

    /* Check recursively for palindrome starting from both ends */
    return check_recursively(start, end);
}
