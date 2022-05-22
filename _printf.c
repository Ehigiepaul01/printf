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
