#include <stdarg.h>
#include "main.h"

/**
 * README
 * i created the variadic function
 * the complier tells me: "implicite declaration of the test function"
 * i forgot how we used it in out example
 * @num: this is what we will return
 * Return: we needed to return the number of charactors 
 * not the char themselves
 */

int _printf(const char *format, ...)
{
	int i, num = 0;
	const char *str;
	va_list ap;

	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i])
			{
				case 'c':
				{
					num += _putchar(va_arg(ap, int));
					break;
				}
				case 's':
				{
					str = va_arg(ap, char *);
					while(*str != '\0')
					{
						num += _putchar(*str);
						str++;
					}
					break;
				}
				case '%':
				{
					num += _putchar('%');
					break;
				}
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
	return (num);
}
