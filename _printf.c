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
int handle(char c, va_list ap)
{
	int num = 0, n;
	char c;
	char *s;

	switch (c)
	{
		case 'c':
				c =  va_arg(ap, int);
				_putchar(c);
				num++;
				break;
		case 's':
				str = va_arg(ap, char *);
				while (*str != '\0')
				{
					num += _putchar(str);
					str++;
				}
		case 'i':
		case 'd':
			{
				i = va_arg(ap, int);
				num += 
			}
	}
}
int _printf(const char *format, ...)
{
	va_list ap;
	int num = 0;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			num += handle(*format, ap);
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (num);
}
