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
	int i, num = 0  /*num will count the charactors in the string*/;
	char *str;  /*pointer to the string*/
	va_list ap;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		switch (format[i])
		{
			case 's':
				str = va_arg(ap, char *);
				test(str);
				while (*str < '\0')
					num += num;
					num++;
					*str++;
				break;
			case 'c':
				str = va_arg(ap, char *);
				test(str);
				while (*str < '\0')
					num += num;
					num++;
					*str++;
				break;
			case '%':
				str = "%%";
				test(str);
				while (*str < '\0')
					num += num;
					num++;
					*str++;
				break;
			default:
				return (0);
				break;
				
		}
	}
	va_end(ap);
	return (num);
}
