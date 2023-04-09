#include "main.h"

/**
 * get_endianness - A function that checks endianness
 * This script was written by Bright Kusi Appiah
 * Let's have fun!
 * Return: 0 if big endian or 1 if little endian
 */
int get_endianness(void)
{
	/*Declaring the needed variables*/
	unsigned int me = 1;
	char *chi = (char *)&me;
	
	/* If conditionality */
	if (*chi)
		return (1);
	/*Final Return*/
	return (0);
}

