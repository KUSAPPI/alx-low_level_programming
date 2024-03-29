#include "main.h"

/**
 * binary_to_uint - A finction that converts binary number
 * to an unsigned integer
 * This script was written by Bright Kusi Appiah
 * @b: A pointer to binary string
 * Return: unsigned integer converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int base = 1;
	unsigned int me = 0;
	unsigned int len = 0;

	if (b == NULL)
		return (0);

	while (b[len])
		len++;

	while (len)
	{
		if (b[len - 1] != '0' && b[len - 1] != '1')
			return (0);

		if (b[len - 1] == '1')
			me += base;
		base *= 2;
		len--;
	}
	return (me);
}
