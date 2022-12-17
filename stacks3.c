#include "monty.h"

/**
 * dIv - divide top 2
 * @stack: stack
 * @line: line
 *
 * Return: void
 */
void dIv(stack_t **stack, unsigned int line)
{
	int j = 0;
	stack_t *a = NULL;

	a = *stack;
	for (; a; a = a->next)
		j++;
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n /= (*stack)->n;
	pOp(stack, line);
}

/**
 * mOd - mod top 2
 * @stack: stack
 * @line: line
 *
 * Return: void
 */
void mOd(stack_t **stack, unsigned int line)
{
	int j = 0;
	stack_t *a = NULL;

	a = *stack;
	for (; a; a = a->next)
		j++;
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n %= (*stack)->n;
	pOp(stack, line);
}
/**
 * pStr - print stack as str
 * @stack: stack pointer
 * @line_number: num
 *
 * Return: the number
 */
void pStr(stack_t **stack, unsigned int line_number)
{
	stack_t *a;
	(void)line_number;

	a = *stack;
	if (!a)
	{
		printf("\n");
		return;
	}
	while (a)
	{
		if (a->n <= 0 || a->n > 127)
		{
			printf("\n");
			return;
		}
		_putchar((char)a->n);
		a = a->next;
	}
}
