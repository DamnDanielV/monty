#include "monty.h"
/**
 * open_monty - open the file contain the Monty byte code
 * @file_to_open: file to be opened
 * Return: Void
 */
void open_monty(char *file_to_open)
{
	FILE *fd;
	unsigned int line_n = 0;
	char *buffer = NULL, *del = " \n\t", *tok = NULL, *tokens = NULL;
	size_t n;
	struct stat *st = NULL;

	st = malloc(sizeof(struct stat));
	if (stat(file_to_open, st) != 0)
	{
		printf("Error: Cant open file %s\n", file_to_open);
		free(st);
		exit(EXIT_FAIL);
	}
	free(st);
	fd = fopen(file_to_open, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file_to_open);
		exit(EXIT_FAIL);
	}
	while (getline(&buffer, &n, fd) != -1)
	{
		tok = strtok(buffer, del);
		if (tok == NULL)
		{
			fclose(fd);
			free(buffer);
			printf("Error\n");
			exit(EXIT_FAIL);
		}
		tokens = strtok(NULL, del);
		line_n++;
		command_checker(tok, tokens, line_n);
	}
}
/**
 * command_checker - checks the commands
 * @tok: first command
 * @tokens: second command
 * @line_n: number of line error
 * Return: void nothing
 */
void command_checker(char *tok, char *tokens, unsigned int line_n)
{
	int check;

	check = c_n_args(tok, line_n);
	if (check == 1)
		c_w_args(tok, tokens, line_n);
}

/**
 * c_n_args - checks for the commands without arguments
 * @tok: first command
 * @line_n: number of line error
 * Return: 1 if fails
 */
int c_n_args(char *tok, unsigned int line_n)
{
	int i;

	instruction_t f_n_args[] = {
			{"pall", f_pall},
			{"pint", f_pint},
			{"pop", f_pop},
			{"swap", f_swap},
			{NULL, NULL}
	};
	while (f_n_args[i].opcode)
	{
		if (strcmp(tok, f_n_args[i].opcode) == 0)
			f_n_args[i].f(&head, line_n);
		i++;
	}
	return (EXIT_FAIL);
}
/**
 * c_w_args - checks for the command push and the values
 * @tok: first command
 * @tokens: second command (number to be pushed)
 * @line_n: number of line error
 * Return: void nothing
 */
void c_w_args(char *tok, char *tokens, unsigned int line_n)
{
	int i = 0, n = 0;
	stack_t *stack = NULL;

	instruction_t f_w_args[] = {
			{"push", f_push},
			{NULL, NULL}
	};
	while (f_w_args[i].opcode)
	{
		if (strcmp(tok, f_w_args[i].opcode) == 0)
		{
			if (tokens != NULL && isdigit(*tokens) != 0)
			{
				n = atoi(tokens);
				stack = stack_creator(n);
				f_w_args[i].f(&stack, line_n);
			}
			else
			{
				printf("L%d: usage: push integer\n", line_n);
				exit(EXIT_FAIL);
			}
		}
		i++;
	}
}
