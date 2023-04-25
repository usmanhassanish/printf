#include <stdarg.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>

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
 * _putbin - writes the binary representation of an unsigned integer to stdout
 * @n: The unsigned integer to print in binary
 * Return: On success the number of characters printed.
 */
int _putbin(unsigned int n)
{
	int len = 0;
	unsigned int mask = 1 << ((sizeof(unsigned int) * 8) - 1);

	while (mask != 0)
	{
	if (n & mask)
		len += _putchar('1');
	else
		len += _putchar('0');
		mask >>= 1;
	}
	return (len);
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
		div *= 10;
	while (div != 0)
	{
	len += _putchar((n / div) + '0');
	n %= div;
	div /= 10;
	}
	return (len);
}

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
	case 'b':
		num += _putbin(va_arg(ap, int));
	case 'd': case 'i':
		num += _putint(va_arg(ap, int));
		break;
	case '%':
		num += _putchar('%');
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
		else
		{
			num += _putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (num);
}
