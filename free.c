#include "monty.h"
/**
 * free_f - free the stack
 */

void free_f(void)
{
	if (head)
	{
		while (head->next != NULL)
		{
			head = head->next;
			free(head->prev);
		}
		free(head);
	}
}
