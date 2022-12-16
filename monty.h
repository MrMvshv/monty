#ifndef MONTY
#define MONTY
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob - global struct
 * @arg: second parameter
 * @head: doubly linked list
 *
 * Description: global structure for function use
 */
typedef struct glob
{
	int arg;
	stack_t *head;
} global_t;
extern global_t gVars;

int _putchar(char c);
int _putcherr(char c);
void _print(char *str);
void _prerr(char *str);
int reader(char *file);
stack_t **implement(char buff[], int i, stack_t **stck);
void pushA(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **head);
void pallA(stack_t **stack, unsigned int line_number);
void (*get_func(char *opc))(stack_t **stack, unsigned int line_number);
void pInt(stack_t **stack, unsigned int line);
void pOp(stack_t **stack, unsigned int line);
void sWap(stack_t **stack, unsigned int line);
void Add(stack_t **stack, unsigned int line);
void Sub(stack_t **stack, unsigned int line);
void Mul(stack_t **stack, unsigned int line);
void nOp(stack_t **stack, unsigned int line);
#endif
