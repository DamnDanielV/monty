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
		printf("L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAIL);
	}

	(*head)->next = (*head)->next->next;
	(*head) = (*head)->next->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	(*head)->next->prev = (*head);
	if ((*head)->next->next != NULL)
		(*head)->next->next->prev = (*head)->next;
}
