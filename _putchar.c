#include "main.h"

/**
 * _putchar - writes to the stdout
 * @c: input
 * Return: Always 0
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
