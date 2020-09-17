#include "monty.h"
/**
 * f_swap -  swaps the top two elements
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_swap(stack_t **head, unsigned int line_n)
{
	int temp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%d: can't swap, stack too short\n", line_n);
		free_f();
		exit(EXIT_FAIL);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
/**
 * f_add -  adds the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_add(stack_t **head, unsigned int line_n)
{
	stack_t *temp;
	int c = 0, sum = 0;

	temp = *head;
	while (temp)
	{
		c++;
		temp = temp->next;
	}
	if (c < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAIL);
	}
	sum = (*head)->n + (*head)->next->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = sum;
}
/**
 * f_nop -  doesn’t do anything.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_nop(stack_t **head, unsigned int line_n)
{
	(void) *head;
	(void) line_n;
	/*why exists this function?*/
}
