#include "monty.h"
/**
 * pushA - push to stack
 * @stack: stack pointer
 * @line_number: number to push
 *
 * Return: the number
 */
void pushA(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	add_node(stack);
}

/**
 * pallA - print stack
 * @stack: stack pointer
 * @line_number: num
 *
 * Return: the number
 */
void pallA(stack_t **stack, unsigned int line_number)
{
	stack_t *a;
	(void)line_number;

	a = *stack;
	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}
