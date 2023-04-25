#include <limits.h>
#include "main.h"
/**
 * to_unsigned - changes an in to unsigned int
 * @num: int
 * Return: unsigned int
 */
unsigned int to_unsigned(int num)
{
	if (num < 0)
	{
		return (unsigned int (num + UINT_MAX + 1));
	}
	else
		return (unsigned int num);
}

