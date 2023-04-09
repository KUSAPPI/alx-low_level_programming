#include "main.h"

/**
 * clear_bit - A function that sets a bit to 0 at given an index
 * Script was written by Bright Kusi Appiah
 * @n: The number to set the bit in
 * @index: The index to set the bit at
 * Return: 1 if it worked, or -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Declaring the if conditionality */
	if (index > 63)
		return (-1);

	/* End part of code */
	*n = (~(1UL << index) & *n);
	return (1);
}
