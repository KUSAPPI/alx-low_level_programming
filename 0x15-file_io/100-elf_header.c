#include <elf.h>
/*#include <sys/types.h>*/
/*#include <sys/stat.h>*/
/*#include <fcntl.h>*/
/*#include <unistd.h>*/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*Preprocessors added above*/

void elf_check(unsigned char *e_ident);
void magic_print(unsigned char *e_ident);
void class_print(unsigned char *e_ident);
void data_print(unsigned char *e_ident);
void version_print(unsigned char *e_ident);
void abinn_printer(unsigned char *e_ident);
void obibi_print(unsigned char *e_ident);
void type_print(unsigned int e_type, unsigned char *e_ident);
void entry_print(unsigned long int e_entry, unsigned char *e_ident);
void elf_closer(int elf);

/**
 * elf_check - (_)Checks if a file (_) is an ELF file.
 * @e_ident: (_)A pointer to an array (_) containing the ELF magic numbers.
 *
 * Description: (_)If the file is not an ELF (_)file - exit code 98.(_)
 */
void elf_check(unsigned char *e_ident)
{
	int me;
	/*This variable above is for 'index'*/

	for (me = 0; me < 4; me++)
	{
		if (e_ident[me] != 127 &&
		    e_ident[me] != 'E' &&
		    e_ident[me] != 'L' &&
		    e_ident[me] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic_print - (_)Prints the magic (_)numbers of an ELF (_)header.
 * @e_ident: A (_)pointer to an (_)array containing the ELF (_)magic numbers.
 * (_)
 * Description: (_)Magic numbers are (_)separated by (_)spaces.
 */
void magic_print(unsigned char *e_ident)
{
	int me;

	printf("  Magic:   ");

	for (me = 0; me < EI_NIDENT; me++)
	{
		printf("%02x", e_ident[me]);

		if (me == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class_print - (_)Prints the (_)class of (_)an ELF (_)header.
 * @e_ident: (_)A pointer to an (_)array containing the (_)ELF class(_).
 */
void class_print(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * data_print - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void data_print(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * version_print - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void version_print(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * obibi_print - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void obibi_print(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * abinn_printer - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void abinn_printer(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * type_print - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void type_print(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * entry_print - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void entry_print(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * elf_closer - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void elf_closer(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_closer(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		elf_closer(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_check(header->e_ident);
	printf("ELF Header:\n");
	magic_print(header->e_ident);
	class_print(header->e_ident);
	data_print(header->e_ident);
	version_print(header->e_ident);
	obibi_print(header->e_ident);
	abinn_printer(header->e_ident);
	type_print(header->e_type, header->e_ident);
	entry_print(header->e_entry, header->e_ident);

	free(header);
	elf_closer(o);
	return (0);
}