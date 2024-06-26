#include "monty.h"

/**
 * error - Prints the right error messages determined by error code.
 * @errorCode: The error codes bellow:
 * case1 > The user does not give any file or more than one file to the program.
 * case2 > The file provided is not a file that can be opened or read.
 * case3 > The file provided contains an invalid instruction.
 * case4 > When the program is unable to malloc more memory.
 * case5 > When the parameter passed to the instruction "push" is not an int.
 */
void error(int errorCode, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, errorCode);
	switch (errorCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * error2 - handles errors.
 * @errorCode: The error codes bellow:
 * case6 > When the stack it empty for pint.
 * case7 > When the stack it empty for pop.
 * case8 > When stack is too short for operation.
 * case9 > Division by zero.
 */
void error2(int errorCode, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, errorCode);
	switch (errorCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * error3- handles errors.
 * @errorCode: The error codes bellow:
 * case10 > The number inside a node is outside ASCII bounds.
 * case11 > The stack is empty.
 */
void error3(int errorCode, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, errorCode);
	l_num = va_arg(ag, int);
	switch (errorCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
