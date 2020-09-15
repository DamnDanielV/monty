#include "monty.h"
/**
 * stack_creator - creates a stack with the data n
 * @n: data to be inserted in the stack
 * Return: pointer to the stack
 */
stack_t *stack_creator(int n)
{
	stack_t *stack = malloc(sizeof(stack_t));

	if (stack == NULL)
	{
		printf("Error: Fail allocating memory\n");
		exit(EXIT_FAIL);
	}
	stack->n = n;
	return (stack);
}

/**
 * f_pall - prints all the values on the stack
 * @head: pointer to the first element on stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_pall(stack_t **head, unsigned int line_n)
{
	stack_t *temp;

	(void) line_n;

	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * f_push - pushes an element to the stack
 * @stack: pointer to the new element
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_push(stack_t **stack, unsigned int line_n)
{
	(void) line_n;

	(*stack)->prev = NULL;
	(*stack)->next = head;
	if (((*stack)->next) != NULL)
		(*stack)->next->prev = (*stack);
	head = (*stack);
}
