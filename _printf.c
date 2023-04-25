#include <stdarg.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>
/**
 * handle_format_specifier - handles format specifier and writes to stdout
 * @spec: format specifier character
 * @ap: va_list argument pointer
 *
 * Return: number of characters written to stdout
 */
int handle_format_specifier(char spec, va_list ap)
{
	int num = 0;
	const char *str;

	switch (spec)
	{
		case 'c':
			num += _putchar(va_arg(ap, int));
			break;
		case 's':
			str = va_arg(ap, const char *);
			while (*str != '\0')
			{
				num += _putchar(*str);
				str++;
			}
			break;
		case 'd': case 'i': case 'b':
			num += _putint(va_arg(ap, int));
			break;
		case '%':
			num += _putchar('%');
			break;
			break;
		default:
			break;
	}
	return (num);
}
/**
 * _printf - prints formatted output to stdout
 * @format: pointer to format string
 * @...: variable number of additional arguments
 *
 * Return: number of characters written to stdout
 */
int _printf(const char *format, ...)
{
	int num = 0;
	va_list ap;

	va_start(ap, format);
	if (!format && format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			num += handle_format_specifier(*format, ap);
		}
		if (*format == "%b")
		{
			format++;
			to _unsigned(num);
			num += handle_format_specifier(*format, ap);
			to_binary(num);
		}
		else
		{
			num += _putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (num);
}
