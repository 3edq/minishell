#include "../include/lexer.h"
#include "../include/parser.h"

t_command	*new_command(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->append = 0;
	cmd->delimiter = NULL;
	cmd->heredoc_fd = -1;
	cmd->heredoc_filename = NULL;
	cmd->next = NULL;
	return (cmd);
}

static int	add_argument(t_command *cmd, char *arg)
{
	int		count;
	char	**new_args;

	count = 0;
	if (cmd->args)
	{
		while (cmd->args[count])
			count++;
	}
	new_args = ft_realloc(cmd->args, sizeof(char *) * (count + 2));
	if (!new_args)
		return (0);
	new_args[count] = ft_strdup(arg);
	if (!new_args[count])
		return (0);
	new_args[count + 1] = NULL;
	cmd->args = new_args;
	return (1);
}

static int	process_token(t_lexer **lexer_list, t_command **current)
{
	int	ret;

	ret = handle_pipe(lexer_list, current);
	if (ret == 1)
		return (1);
	ret = which_redirect(lexer_list, *current);
	if (ret != 0)
		return (ret);
	if ((*lexer_list)->token == TOKEN_WORD)
	{
		if ((*lexer_list)->str && (*lexer_list)->str[0] != '\0')
		{
			if (!add_argument(*current, (*lexer_list)->str))
			{
				fprintf(stderr, "Memory allocation error\n");
				return (-1);
			}
		}
		*lexer_list = (*lexer_list)->next;
	}
	return (0);
}

t_command	*parse_tokens(t_lexer *lexer_list)
{
	t_command	*head;
	t_command	*current;
	int			ret;

	current = new_command();
	if (!current)
		return (NULL);
	head = current;
	while (lexer_list)
	{
		ret = process_token(&lexer_list, &current);
		if (ret == -1)
			return (head);
	}
	return (head);
}
