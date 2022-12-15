#include "monty.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _putcherr - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putcherr(char c)
{
	return (write(2, &c, 1));
}

/**
 * _print - prints string to stdout
 * @str: the string pointer
 *
 * Return: void
 */

void _print(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _prerr - prints string to stderr
 * @str: the string pointer
 *
 * Return: void
 */

void _prerr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putcherr(str[i]);
		i++;
	}
}
