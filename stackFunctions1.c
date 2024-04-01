#include "monty.h"


/**
 * printStack - prints the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: line number of  the opcode.
 */
void printStack(stack_t **stack, unsigned int lNo)
{
    stack_t *tmp;

    (void) lNo;
    if (stack == NULL)
        exit(EXIT_FAILURE);
    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * pushToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @lNo: the line number of of the opcode.
 */
void pushToStack(stack_t **newNode, __attribute__((unused))unsigned int lNo)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	head = *newNode;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * popTop - pop the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void popTop(stack_t **stack, unsigned int lNo)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		error2(7, lNo);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * printTop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void printTop(stack_t **stack, unsigned int lNo)
{
	if (stack == NULL || *stack == NULL)
		error2(6, lNo);
	printf("%d\n", (*stack)->n);
}
