#include "monty.h"

/**
 * addNodes - Adds top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void addNodes(stack_t **stack, unsigned int lNo)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        error2(8, lNo, "add");

    (*stack) = (*stack)->next;
    sum = (*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}


/**
 * subNodes - subtract top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void subNodes(stack_t **stack, unsigned int lNo)
{
    int sub;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

        error2(8, lNo, "sub");


    (*stack) = (*stack)->next;
    sub = (*stack)->n - (*stack)->prev->n;
    (*stack)->n = sub;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}


/**
 * divNodes - Divides top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lNo: the line number of of the opcode.
 */
void divNodes(stack_t **stack, unsigned int lNo)
{
    int div;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        error2(8, lNo, "div");

    if ((*stack)->n == 0)
        error2(9, lNo);
    (*stack) = (*stack)->next;
    div = (*stack)->n / (*stack)->prev->n;
    (*stack)->n = div;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}



/**
 * mulNodes - multiply top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack(head).
 * @lNo: the line number of of the opcode.
 */
void mulNodes(stack_t **stack, unsigned int lNo)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, lNo, "mul");

	(*stack) = (*stack)->next;
    mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modNodes - mod top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack(head).
 * @lNo: the line number of of the opcode.
 */
void modNodes(stack_t **stack, unsigned int lNo)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error2(8, lNo, "mod");


	if ((*stack)->n == 0)
		error2(9, lNo);
	(*stack) = (*stack)->next;
    mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
