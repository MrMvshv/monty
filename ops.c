#include "monty.h"

/**
 * add_node - adds a node to beginning of dll
 * @head: head node
 *
 * Return: a dll
 */
stack_t *add_node(stack_t **head)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp->n = gVars.arg;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}
/**
 * freeStack - free stack
 * @head: stack
 *
 * Return: NULL
 */
void freeStack(stack_t **head)
{
	stack_t *tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
