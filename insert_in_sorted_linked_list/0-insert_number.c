#include "lists.h"

/**
 * insert_node - Inserts a node at the correct position in a sorted linked list
 * @head: Pointer to the pointer of the head of the list
 * @number: The value to assign to the new node
 * Return: Pointer to the new node, or NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
    if (!head)
        return NULL;

    listint_t *new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return NULL;

    new_node->n = number;

    if (!*head || number < (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    listint_t *current = *head;
    while (current->next && number >= current->next->n)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}
