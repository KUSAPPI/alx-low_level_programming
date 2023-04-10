#include "main.h"

/**
 * append_text_to_file - Function that appends a text at the end to a file
 * This file is for educational purposes
 * @filename: This is the name of the file to append text in
 * @text_content: This is tthe string to append to file
 * Return: Return 1 on success, return -1 if the file can't be created,
 * or written to,
 * or the write fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int me, me1, len = 0;
	/* The variables declared above for operations */

	if (filename == NULL)
		return (-1);

	me = open(filename, O_RDWR | O_APPEND);
	if (me < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(me);
		return (1);
	}

	while (*(text_content + len))
		len++;

	me1 = write(me, text_content, len);
	close(me);
	if (me1 < 0)
		return (-1);

	return (1);
}
