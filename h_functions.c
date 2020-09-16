#include "monty.h"
/**
* check_is_num - checks if the arguments are numbers
* @tokens: Argument to check for ints
* Return: argument or -1 if fails
*/
int check_is_num(char *tokens)
{
	int num = 0, i = 0;

	if (tokens && isdigit(*tokens))
	{
		while (tokens[i] != '\0')
		{
			if (isdigit(tokens[i] == 0))
				return (-1);
		}
		num = atoi(tokens);
		return (num);
	}
	return (-1);
}
