/**
 * _putuint - writes the unsigned integer n to stdout
 * @n: The unsigned integer to print
 *
 * Return: On success the number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putuint(unsigned int n)
{
	unsigned int div = 1;
	int len = 0;

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
