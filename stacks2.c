#include "monty.h"
/**
 * Add - adds top 2
 * @stack: stack
 * @line: line
 *
 * Return: void
 */
void Add(stack_t **stack, unsigned int line)
{
	int j = 0;
	stack_t *a = NULL;

	a = *stack;
	for (; a; a = a->next)
		j++;
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n += (*stack)->n;
	pOp(stack, line);
}

/**
 * nOp - nothing
 * @stack: stack
 * @line: line
 *
 * Return: void
 */
void nOp(stack_t **stack, unsigned int line)
{
	(void) line;
	(void) stack;
}

/**
 * Sub - subs top 2
 * @stack: stack
 * @line: line
 *
 * Return: void
 */
void Sub(stack_t **stack, unsigned int line)
{
	int j = 0;
	stack_t *a = NULL;

	a = *stack;
	for (; a; a = a->next)
		j++;
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n -= (*stack)->n;
	pOp(stack, line);
}

/**
 * Mul - muls top 2
 * @stack: stack
 * @line: line
 *
 * Return: void
 */
void Mul(stack_t **stack, unsigned int line)
{
	int j = 0;
	stack_t *a = NULL;

	a = *stack;
	for (; a; a = a->next)
		j++;
	if (j < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n *= (*stack)->n;
	pOp(stack, line);
}
