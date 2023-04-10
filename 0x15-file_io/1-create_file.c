#include "main.h"

/**
 * create_file - A function that creates a new file
 * This file is for educational purposes
 * @filename: The name of the file to create
 * @text_content: A NULL terminated pointer string to write to the file
 * Return: 1 on success, -1 if file, cannot be created, or written to,
 * or the write fails.
 */
int create_file(const char *filename, char *text_content)
{
        int me, me1, len = 0;

        if (filename == NULL)
                return (-1);

        me = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
        if (me < 0)
                return (-1);

        while (text_content && *(text_content + len))
                len++;

        me1 = write(me, text_content, len);
        close(me);
        if (me1 < 0)
                return (-1);
        return (1);
}
