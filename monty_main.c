#include "monty.h"

global_t gVars;
/**
 * get_func - func getter
 * @opc: opcode
 *
 * Return: func pointer
 */
void (*get_func(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t inst[] = {{"push", pushA}, {"pall", pallA},
		{"pint", pInt}, {"pop", pOp}, {"swap", sWap},
		{"add", Add}, {"nop", nOp}, {"sub", Sub}, {"mul", Mul},
		{NULL, NULL}};
	int i;

	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(inst[i].opcode, opc) == 0)
			break;
	}
	return (inst[i].f);
}
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
	int j, ext = 0;
	void (*f)(stack_t **stack, unsigned int line_number);
	char *ops[] = {"push", "pall", "pint", "pop",
		"swap", "add", "nop", "sub", "mul", NULL};
	char *str = NULL, *spc = " ", *s;

	str = buff;
	if (!(str[0] >= 'a' && str[0] <= 'z'))
		str = strVerif(str);
	if (str)
		str = strtok(str, spc);
	if (str == NULL)
		return (NULL);
	for (j = 0; 1 ; j++)
	{
		if (ops[j] == NULL)
		{	fprintf(stderr, "L%d: unknown instruction %s\n", i, str);
			exit(EXIT_FAILURE);
		}
		if (_strcmp(str, ops[j]) == 0)
		{	s = strtok(NULL, spc);
			if (s != 0)
			{
				if (*s == 48)
					gVars.arg = 0;
				else
				{	ext = atoi(s);
					if (ext == 0 && j == 0)
					{	fprintf(stderr, "L%d: usage: push integer\n", i);
						exit(EXIT_FAILURE);
					}
					gVars.arg = ext;
				}
			}
			f = get_func(ops[j]);
			f(&gVars.head, i);
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
		fprintf(stderr, "Error: Can't open file %s\n", file);
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
	freeStack(&gVars.head);
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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		reader(av[1]);
	}
	return (0);
}
