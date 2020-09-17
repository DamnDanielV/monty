#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_pchar(stack_t **head, unsigned int line_n)
{
	int num;

	if (!(*head) || !head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAIL);
	}
	num = (*head)->n;
	if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
		printf("%c\n", num);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
		exit(EXIT_FAIL);
	}
}
/**
 * f_pstr - prints the string starting at the top of the stack
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_pstr(stack_t **head, unsigned int line_n)
{
	(void)line_n;
	if (!(*head) || !head)
	{
		printf("\n");
	}
	else
	{
		while (*head && (*head)->n != 0)
		{
			if (((*head)->n >= 1 && (*head)->n <= 127))
			{
				printf("%c", (*head)->n);
				(*head) = (*head)->next;
			}
			else
				break;
		}
		printf("\n");
	}
}
/**
 * f_rotl - rotates the stack to the top.
 * @head: pointer to the head of the stack
 * @line_n: Number line where the code fails.
 * Return: void nothing
 */
void f_rotl(stack_t **head, unsigned int line_n)
{
	stack_t *temp;

	(void)line_n;

	if (*head && head && (*head)->next)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		(*head) = (*head)->next;
		temp->next = (*head)->prev;
		(*head)->prev = NULL;
		temp->next->next = NULL;
		temp->next->prev = temp;
	}
}
