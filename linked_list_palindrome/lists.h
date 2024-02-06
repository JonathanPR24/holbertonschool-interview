#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Definition of listint_t */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/* Function declarations */
size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
int is_palindrome(listint_t **head);
void free_listint(listint_t *head);

#endif /* LISTS_H */
