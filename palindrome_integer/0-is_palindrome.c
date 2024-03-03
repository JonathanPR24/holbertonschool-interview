#include "palindrome.h"

/*
 * is_palindrome - check if an integer is a palindrome
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0;
    unsigned long temp = n;

    while (temp != 0)
    {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    return (n == reversed) ? 1 : 0;
}
