#include "main.h"
/**
 * print_integer - prints an integer recursively
 * @number: input value
 * Return: Always 0
 */

int print_integer(int number)
{
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	if (number / 10)
	{
		print_integer(number / 10);
	}
	_putchar((number % 10) + '0');

}
