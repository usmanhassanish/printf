#include "main.h"
#include <stdarg.h>

/**
 * _itoa - converts an integer to a string
 * @value: the integer value to convert
 * @buffer: buffer to store the result
 * @base: base for conversion (e.g., 10 for decimal)
 * Return: pointer to the resulting string
 */
char *_itoa(int value, char *buffer, int base)
{
	char *ptr = buffer;
	int temp_value;
	int num_digits = 0;

	if (value == 0)
	{
		*ptr++ = '0';
		*ptr = '\0';
		return buffer;
	}

	if (value < 0)
	{
		*ptr++ = '-';
		value = -value;
	}

	temp_value = value;
	while (temp_value)
	{
		temp_value /= base;
		num_digits++;
	}
	ptr += num_digits;
	*ptr = '\0';

	while (value)
	{
		int digit = value % base;
		*--ptr = digit + '0';
		value /= base;
	}
	return buffer;
}
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
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
            		{
				int j = 0;
				
        			int value = va_arg(ap, int);
                		char buffer[12];
                		_itoa(value, buffer, 10);
                		while (buffer[j] != '\0')
                		{
                    			_putchar(buffer[j]);
                    			j++;
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
