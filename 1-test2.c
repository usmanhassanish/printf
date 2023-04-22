#include <stdarg.h>

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
				/* here i tried to use va_arg 
				 * (since it is a variadic function)
				 * to store the argument in str
				 */
				test(str);
				/* here i called the test function to get the string
				 * alvernatively i thought we could use the _putchar
				 * to print the char in the string and 
				 * store it in str and num counts the char's in str
				 */
				while (*str < '\0')
					num += num;
					num++;
					*str++;
				/* here i went through the sting to get num */
				break;
			case 'c':
				str = "%c";
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
