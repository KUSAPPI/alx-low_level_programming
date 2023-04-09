#include "main.h"

/**
 * print_binary - A function that prints a binary number 
 * This has to be done without % or /
 * This script was written by Bright Kusi Appiah
 * @n: The number to be printed
 * Return: Nothing
 */
void print_binary(unsigned long int n)
{
	unsigned int me = 0, me1 = 32768; 
	/* 1000 0000 0000 0000 */

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while (me1)
	{
		if (me == 1 && (n & me1) == 0)
			_putchar('0');
		else if ((n & me1) != 0)
		{
			_putchar('1');
			me = 1;
		}
		me1 >>= 1;
	}
}
