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
	int me;
	/* Declaring the 'me' variable */
	/* If statement to check for conditionality */
	if (index > 63)
		return (-1);
	me = (n >> index) & 1;
	return (me);
}
