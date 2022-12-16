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
/**
 * _strcmp - compare e strings
 * @s1: str 1
 * @s2: str 2
 *
 * Return: 0 if same
 */
int _strcmp(char *s1, char *s2)
{
	int m = 0, n = 0;

	while (s1[m])
		m++;
	while (s2[n])
		n++;

	if (m > 4 && (s1[4] != '\n'))
		return (1);
	if (n == 3 && (s1[3] != '\n'))
		return (1);
	else
		return (strncmp(s1, s2, 3));
}
