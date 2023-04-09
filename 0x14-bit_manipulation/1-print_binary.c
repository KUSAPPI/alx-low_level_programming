#include "main.h"

/**
 * print_binary - A function that prints a binary number without % or /
 * This script was written by Bright Kusi Appiah
 * @n: The number set to be printed
 * Return: Nothing. This function returns nothing.
 */
void print_binary(unsigned long int n)
{
	int me1, me_read = 0;
	/* Declare variables */
	unsigned long int me_present;
	/* More variables above */

	for (me1 = 63; me1 >= 0; me1--)
	{
		me_present = n >> me1;

		if (me_present & 1)
		{
			_putchar('1');
			me_read++;
		}
		else if (me_read)
			_putchar('0');
	}
	if (!me_read)
		_putchar('0');
}
