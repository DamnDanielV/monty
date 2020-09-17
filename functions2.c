#include "monty.h"
/**
 * f_swap -  swaps the top two elements
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_swap(stack_t **head, unsigned int line_n)
{

	int c = 0;
	stack_t *temp;

	temp = *head;
	while (temp)
	{
		c++;
		temp = temp->next;
	}
	if (c < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		free_f();
		exit(EXIT_FAIL);
	}
	(*head) = (*head)->next;
	(*head)->prev->next = (*head)->next;
	(*head)->prev->prev = (*head);
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	if ((*head)->next->next != NULL)
		(*head)->next->next->prev = (*head)->next;
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
