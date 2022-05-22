#include "main.h"
/**
 * _printf - immitates the printf int the stdio.h
 * @format: formatted strings
 * Return: Always 0
 */

int _printf(char* format, ...)
{
	char *transcript, *s;
	unsigned int i;
	int number_count = -1;
	va_list args;
	va_start(args, format);

	for (transcript = format; *transcript != '\0'; *transcript++)
	{
		while (*transcript != '%')
		{
			_putchar(*transcript);
			number_count++, transcript++;
		}
		transcript++;
	}
	switch(*transcript)
	{
		case 's': s = va_arg(args, char *);
					print_string(s);
					number_count ++;
					break;
		case '%': s = va_arg(args, char *);
					_putchar('%');
					number_count++;
					break; 
		case 'd': i = va_arg(args, unsigned int);
				print_integer(i);
				break;
		case 'c': s = va_arg(args, char *);
				_putchar(*s);
				number_count++;
		case 'i': i = va_arg(args, unsigned int);
				print_integer(i);
				break;
	}
	va_end(args);
	return (number_count);
}

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

/**
 * _putchar - writes to the stdout
 * @c: input
 * Return: Always 0
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
