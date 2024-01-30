#include "main.h"
#include <stdarg.h>
/**
 * _printf - custom printf
 * @format: format specifier
 * Return: returns number of characters
 */
int _printf(const char *format, ...)
{
	int charPrinted = 0, i = 0, charsP = 0;
	va_list ap;

	while (format[charPrinted] != '\0')
		charPrinted++;
	va_start(ap, format);
	while (i < charPrinted)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charsP++;
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(ap, int));
				charsP++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(ap, char *);
				int k = 0;

				while (str[k] != '\0')
				{
					_putchar(str[k]);
					k++;
					charsP++;
				}
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				charsP++;
				i++;
			}
		}
		i++;
	}
	va_end(ap);
	return (charsP);
}
