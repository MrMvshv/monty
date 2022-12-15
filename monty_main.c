#include "monty.h"

global_t gVars;
/**
 * implement - implements opcode
 * @buff: str containing opcode
 * @i: line number
 * @stck: stack
 *
 * Return: 0
 */
stack_t **implement(char buff[], int i, stack_t **stck)
{
	int j;
	int ext = 0;
	char *spc = " ", *s;
	instruction_t inst[] = {{"push", pushA}, {"pall", pallA}, {NULL, NULL}};
	char *str = NULL;

	str = strtok(buff, spc);
	for (j = 0; 1 ; j++)
	{
		if (inst[j].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", i, str);
			exit(EXIT_FAILURE);
		}

		if (strncmp(str, inst[j].opcode, 4) == 0)
		{
			s = strtok(NULL, spc);

			if (s != 0)
			{
				if (*s == 48)
					gVars.arg = 0;
				else
				{
					ext = atoi(s);
					if (ext == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", i);
						exit(EXIT_FAILURE);
					}
					gVars.arg = ext;
				}
			}

			inst[j].f(&gVars.head, i);
			break;
		}
	}
	return (stck);
}

/**
 * reader - reads a file
 * @file: filepath
 *
 * Return: 0
 */
int reader(char *file)
{
	int i = 0;
	FILE *fl;
	char buff[256];

	fl = fopen(file, "r");
	if (!fl)
	{
		_prerr("Error: Can't open file ");
		_prerr(file);
		_putchar(10);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (fgets(buff, 256, fl) != NULL)
		{
			i++;
			implement(buff, i, &gVars.head);
		}
	}
	fclose(fl);

	return (0);
}

/**
 * main - reads file and error handles
 * @ac: no of args
 * @av: array of args
 *
 * Return: 0
 */
int main(int ac, char *av[])
{
	if (ac == 1 || ac > 2)
	{
		_prerr("USAGE: monty file");
		_putchar(10);
		exit(EXIT_FAILURE);
	}
	else
	{
		reader(av[1]);
	}
	return (0);
}
