#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int total = 0, i;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
			{
				total += printf("%c", va_arg(args, int));
			}
			else if (format[i] == 's')
			{
				total += printf("%s", va_arg(args, char *));
			}
			else if (format[i] == '%')
			{
				total += printf("%%");
			}
			else
			{
				putchar('%');
				total++;

				putchar(format[i]);
				total++;
			}
		}
		else
		{
			putchar(format[i]);
			total++;
		}
	}

	va_end(args);
	return (total);
}
