#include <stdlib.h>
#include <string.h>
/**
 * to_binary - converts int to binary
 * @num: int
 * Return: binary
 */
char *to_binary(unsigned int num)
{
	int i, bits;
	char *bin;

	bits = sizeof(unsigned int) * 8;
	bin = malloc(bits + 1);
	memset(bin, '0', bits);
	bin[bits] = '\0';
	i = bits - 1;
	while (num > 0 && i >= 0)
	{
		bin[i--] = (num & 1) + '0';
		num >>= 1;
	}
	return (bin);
}
