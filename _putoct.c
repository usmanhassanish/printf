#include <math.h>
#include <stdio.h>
#include "main.h"
/**
 * _putoct - writes the integer n as an octal number to stdout
 * @n: The integer to print
 *
 * Return: On success the number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putoct(int n)
{
	unsigned int oct = 0, rem = 0;
	int len = 0, is_negative = 0;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	while (n != 0)
	{
		oct += (n % 8) * pow(10, rem);
		n /= 8;
		rem++;
	}

	while (rem > 0)
	{
		len += _putchar((oct / pow(10, rem - 1)) + '0');
		oct %= (unsigned int)pow(10, rem - 1);
		rem--;
	}

	if (is_negative)
	{
		len += _putchar('-');
	}

	return (len);
}
