#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints number of charactors
 * @format: pointer
 * Return: number of charactors
 */

int _printf(const char *format, ...)
{
	int i, num = 0;
	const char *str;
	va_list ap;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i])
			{
				case 'c':
					num += _putchar(va_arg(ap, int));
					break;
				case 's':
					str = va_arg(ap, char *);
					while (*str != '\0')
					{
						num += _putchar(*str);
						str++;
					}
					break;
				case '%':
					num += _putchar('%');
					break;
				default:
					break;
			}
		}
		else
		{
			num += _putchar(*format);
		}
		format++;
	}
	va_end(ap);
	_putchar('\n');
	return (num);
}
