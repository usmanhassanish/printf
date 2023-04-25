#include "main.h"
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
