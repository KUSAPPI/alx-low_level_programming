#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int close_me(int);
/**
 * main - This the main function that copies files
 * @argc: The number of arguments to be passed
 * @argv: Array arguments pointers
 * Return: Return 1 on success, or exit on failure
 */
int main(int argc, char *argv[])
{
	/*char buffer_use[1024];*/
	/*Variables declared below*/
	int readBytes = 0, end_of_file = 1, getit = -1, getto = -1, error_occured = 0;
	char buffer_use[1024];

	/*If conditionality*/
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	getit = open(argv[1], O_RDONLY);
	if (getit < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	getto = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (getto < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_me(getit);
		exit(99);
	}

	while (end_of_file)
	{
		end_of_file = read(getit, buffer_use, 1024);
		if (end_of_file < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close_me(getit);
			close_me(getto);
			exit(98);
		}
		else if (end_of_file == 0)
			break;
		readBytes += end_of_file;
		error_occured = write(getto, buffer_use, end_of_file);
		if (error_occured < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_me(getit);
			close_me(getto);
			exit(99);
		}
	}
	error_occured = close_me(getto);
	if (error_occured < 0) /*If conditionality*/
	{
		close_me(getit);
		exit(100);
	}
	error_occured = close_me(getit);
	if (error_occured < 0)
		exit(100);
	return (0);
}

/**
 * close_me - This is a function that closes the file and,
 * prints the notice 'error_occured when file is closed'
 * @description: This is a description for error_occured for file closed
 * Return: Return 1 on success, or -1 on a failure
 */
int close_me(int description)
{
	int error_occured;

	error_occured = close(description);
	if (error_occured < 0)
		dprintf(STDERR_FILENO, "error_occured: Can't close fd %d\n", description);
	return (error_occured);
}
