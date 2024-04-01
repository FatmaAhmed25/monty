#include "monty.h"


/**
 * swapNodes - Swaps top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void swapNodes(stack_t **stack, unsigned int lNo)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, lNo, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * nop - Doesn't do anything.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int lNo)
{
    (void)stack;
    (void)lNo;
}

