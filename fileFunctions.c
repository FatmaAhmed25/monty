#include "monty.h"

/**
 * openFile - opens a file
 * @fname: the file namepath
 * Return: void
 */

void openFile(char *fname)
{
	FILE *fd = fopen(fname, "r");

	if (fname == NULL || fd == NULL)
		error(2, fname);

	readFile(fd);
	fclose(fd);
}


/**
 * readFile - reads a file
 * @fileDescriptor: pointer to file descriptor
 * Return: void
 */

void readFile(FILE *fileDescriptor)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fileDescriptor) != -1; line_number++)
	{
		format = parseLine(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parseLine - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseLine(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunction(opcode, value, line_number, format);
	return (format);
}

/**
 * findFunction - find appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @lNo: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findFunction(char *opcode, char *value, int lNo, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", pushToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", nop},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", printAChar},
		{"pstr", printString},
		{"rotl", rotateFirst},
		{"rotr", rotate},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callFunction(func_list[i].f, opcode, value, lNo, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, lNo, opcode);
}


/**
 * callFunction - Calls required function.
 * @function: Pointer to the function that is about to be called.
 * @opCode: the opcode.
 * @value: numeric value.
 * @lNo: line number for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 node will be entered as a queue.
 */
void callFunction(op_func function, char *opCode, char *value, int lNo, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opCode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
            value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			error(5, lNo);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				error(5, lNo);
		}
		node = createNode(atoi(value) * flag);
		if (format == 0)
			function(&node, lNo);
		if (format == 1)
            pushInQueue(&node, lNo);
	}
	else
		function(&head, lNo);
}
