#include "monty.h"

/**
 * printAChar - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void printAChar(stack_t **stack, unsigned int lNo)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		error3(11, lNo);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		error3(10, lNo);
	printf("%c\n", ascii);
}

/**
 * printString - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void printString(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotateFirst - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void rotateFirst(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotate - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void rotate(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
