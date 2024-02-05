#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *prev_slow = NULL, *second_half = NULL;
    int palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return 1;  // Empty list or single-node list is a palindrome

    // Move 'fast' to the middle and reverse the second half
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        // Reverse the second half
        listint_t *temp = slow->next;
        slow->next = prev_slow;
        prev_slow = slow;
        slow = temp;
    }

    // Adjust pointers based on even or odd length
    if (fast != NULL)
        slow = slow->next;

    second_half = slow;  // Head of the reversed second half

    // Compare the first and reversed second halves
    while (prev_slow != NULL && second_half != NULL)
    {
        if (prev_slow->n != second_half->n)
        {
            palindrome = 0;
            break;
        }

        prev_slow = prev_slow->next;
        second_half = second_half->next;
    }

    // Restore the linked list to its original state (if needed)
    prev_slow = NULL;
    while (slow != NULL)
    {
        listint_t *temp = slow->next;
        slow->next = prev_slow;
        prev_slow = slow;
        slow = temp;
    }
    *head = prev_slow;

    return palindrome;
}
