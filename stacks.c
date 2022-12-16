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
/**
 * pInt - print top value
 * @stack: stack pointer
 * @line: line num
 *
 * Return: nothing
 */
void pInt(stack_t **stack, unsigned int line)
{
	(void)line;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pOp - pop top value
 * @stack: stack pointer
 * @line: line num
 *
 * Return: nothing
 */
void pOp(stack_t **stack, unsigned int line)
{
	stack_t *a;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	a = *stack;
	*stack = (*stack)->next;
	free(a);
}

/**
 * sWap- swap top value
 * @stack: stack pointer
 * @line: line num
 *
 * Return: nothing
 */
void sWap(stack_t **stack, unsigned int line)
{
	int j = 0;
	stack_t *a = NULL;

	a = *stack;
	for (; a; a = a->next)
		j++;
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	a = *stack;
	*stack = (*stack)->next;
	a->next = (*stack)->next;
	a->prev = *stack;
	(*stack)->next = a;
	(*stack)->prev = NULL;
}
