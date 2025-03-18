/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:15:16 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 16:42:08 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	cmd->heredoc_list = NULL;
	cmd->next = NULL;
	return (cmd);
}

static int	add_argument(t_command *cmd, char *arg)
{
	int		count;
	char	**new_args;
	size_t	old_size;

	count = 0;
	if (cmd->args)
	{
		while (cmd->args[count])
			count++;
	}
	old_size = sizeof(char *) * (count + 1);
	new_args = ft_realloc(cmd->args, old_size, sizeof(char *) * (count + 2));
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
				ft_putstr_fd("Memory allocation error\n", STDERR_FILENO);
				return (-1);
			}
		}
		*lexer_list = (*lexer_list)->next;
	}
	return (0);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

t_command	*parse_tokens(t_lexer *lexer_list, int *last_exit_status)
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
		if (ret == 2)
		{
			*last_exit_status = 2;
			if (head->args)
			{
				free_args(head->args);
				head->args = NULL;
			}
			return (head);
		}
		else if (ret == -1)
			return (head);
	}
	return (head);
}
