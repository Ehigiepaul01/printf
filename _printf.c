#include "main.h"
/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 * _printf - imitates printf in the stdio.h
 * @format: strings to format
 * Return: Always 0
 */

int _printf(char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
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

		switch(*transcript)
	{
		case 's': s = va_arg(args, char *);
					print_string(s);
					number_count++;
					break;
		case '%': s = va_arg(args, char *);
					_putchar(*s + 0);
					number_count++;
					break; 
		case 'd': i = va_arg(args, unsigned int);
				print_integer(i);
				number_count += print_integer(i);
				break;
		case 'c': s = va_arg(args, char *);
				_putchar('%');
				number_count++;
				break;
		case 'i': i = va_arg(args, unsigned int);
				print_integer(i);
				break;
	}
	va_end(args);
	return (number_count);
	}
}
