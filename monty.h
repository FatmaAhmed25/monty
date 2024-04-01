#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#define _GNU_SOURCE


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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Stack operations*/
stack_t *createNode(int value);
void freeNodes(void);
void callFunction(op_func, char *, char *, int, int);
void printTop(stack_t **, unsigned int);
void popTop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapNodes(stack_t **, unsigned int);
void printStack(stack_t **, unsigned int);
void pushToStack(stack_t **, unsigned int);
void pushInQueue(stack_t **, unsigned int);

/*Math operations with nodes*/
void addNodes(stack_t **, unsigned int);
void subNodes(stack_t **, unsigned int);
void divNodes(stack_t **, unsigned int);
void mulNodes(stack_t **, unsigned int);
void modNodes(stack_t **, unsigned int);


/*file operations*/
void openFile(char *file_name);
int parseLine(char *buffer, int line_number, int format);
void readFile(FILE *);
void findFunction(char *, char *, int, int);


/*String operations*/
void printAChar(stack_t **, unsigned int);
void printString(stack_t **, unsigned int);
void rotateFirst(stack_t **, unsigned int);
void rotate(stack_t **, unsigned int);

/*Error handling*/
void error(int errorCode, ...);
void error2(int errorCode, ...);
void error3(int errorCode, ...);


#endif
