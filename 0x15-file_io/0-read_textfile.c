#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - A function that reads any text file, and prints
 * to the POSIX STDOUT as required
 * This script is for educational purposes (ALX SE)
 * @filename: The filename to open, as required
 * @letters: The number of letters to read, and print as required
 * Return: The number of letters read and printed, print 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int me, me1, me2;
	char *tmpo;

	if (filename == NULL)
		return (0);

	tmpo = malloc(sizeof(char) * letters);
	if (tmpo == NULL)
		return (0);

	me = open(filename, O_RDONLY);
	if (me < 0)
	{
		free(tmpo);
		return (0);
	}

	me1 = read(me, tmpo, letters);
	if (me1 < 0)
	{
		free(tmpo);
		return (0);
	}

	me2 = write(STDOUT_FILENO, tmpo, me1);
	free(tmpo);
	close(me);

	if (me2 < 0)
		return (0);
	return ((ssize_t)me2);
}
