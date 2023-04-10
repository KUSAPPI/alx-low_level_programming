#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- This function reada text file
 * and prints it to the POSIX standard output.
 * This script is for educational purposes.
 * @filename: The text file that is being read
 * @letters: The number of letters that are to be read
 * Return: The actual number of bytes that are read and printed
 * Prints 0 when the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *me;
	ssize_t me2;
	ssize_t me3;
	ssize_t me4;

	me2 = open(filename, O_RDONLY);
	if (me2 == -1)
		return (0);
	me = malloc(sizeof(char) * letters);
	me4 = read(me2, me, letters);
	me3 = write(STDOUT_FILENO, me, me4);

	free(me);
	close(me2);
	return (me3);
}
