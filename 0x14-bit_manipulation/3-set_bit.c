#include "main.h"

/**
 * set_bit - A function that sets a bit at given index to 1
 * This script was written by Bright Kusi Appiah
 * @n: The number to set the bit in
 * @index: The index to set the bit at
 * Return: 1 if it worked, or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int me = 0x01;
	/* Variables declared here */

	me <<= index;
	if (me == 0)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

