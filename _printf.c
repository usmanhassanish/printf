#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putint - writes the integer n to stdout
 * @n: The integer to print
 *
 * Return: On success the number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putint(int n)
{
	int div = 1, len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		n *= -1;
	}
	while (n / div >= 10)
	{
		div *= 10;
	}
	while (div != 0)
	{
		len += _putchar((n / div) + '0');
		n %= div;
		div /= 10;
	}
	return (len);
}
/**
 * binary - converts to binary
 * @num: int
 * Return: void
 */
void binary(unsigned int num)
{
	if (num > 1)
	{
		binary(num / 2);
	}
	_putint(num % 2);
}
/**
 * handle_format_specifier - handles format specifier and writes to stdout
 * @spec: format specifier character
 * @ap: va_list argument pointer
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
			_putchar(*str);
			str++;
			num++;
		}
		break;
	case 'd': case 'i':
		num += _putint(va_arg(ap, int));
		break;
	case 'b':
		binary(va_arg(ap, unsigned int));
		break;
	case 'u':
		num += _putuint(va_arg(ap, unsigned int));
		break;
	case '%':
		num = _putchar('%');
		break;
	default:
		_putchar('%');
		_putchar(spec);
		num += 2;
	}
	return (num);
}
/**
 * _printf - prints formatted output to stdout
 * @format: pointer to format string
 * @...: variable number of additional arguments
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
		else
		{
			_putchar(*format);
			num++;
		}
		format++;
	}
	va_end(ap);
	return (num);
}
