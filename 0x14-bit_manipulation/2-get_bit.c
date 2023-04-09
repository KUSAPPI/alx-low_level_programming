#include "main.h"

/**
 * get_bit - A function that gets a bit at index
 * This script was written by Bright Kusi Appiah
 * @n: The number to get bit from
 * @index: The index where the bit get at
 * Return: Returns the value of the bit or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int me = 63;
	/* Varaibales Declared above */

	me <<= index;
	if (me == 0)
		return (-1);

	if ((n & me))
		return (1);
	else
		return (0);
}
