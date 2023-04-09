/**
 * flip_bits - A function that gets number of bits needed to flip
 * This script was written by Bright Kusi Appiah
 * @n: How many bit flips are needed to equal m for n
 * @m: The number to set other equal to
 * Return: The number of fliped bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* Varaibles are declared below */
	int me, count = 0;
	unsigned long int updated1;
	unsigned long int exclusive = n ^ m;

	for (me = 63; me >= 0; me--)
	{
		updated1 = exclusive >> me;
		if (updated1 & 1)
			count++;
	}

	return (count);
}
