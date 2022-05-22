#include "main.h"
/**
 * print_string - iterates through strings and print it out to the standard output
 * @c: input value
 * Return: returns length of string
 */
char print_string(char *c)
{
    int i, n = 0;
	for (i = 0; c[i] != '\0';i++)
    {
        if (c[i] != '\0')
	    {
            n++;
            _putchar(c[i]);
        }
    }
    return (n);
}
