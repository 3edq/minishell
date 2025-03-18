/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:26:20 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 11:26:22 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

static void	free_heredoc_list(t_heredoc *heredoc_list)
{
	t_heredoc	*current;
	t_heredoc	*next;

	current = heredoc_list;
	while (current)
	{
		next = current->next;
		if (current->delimiter)
			free(current->delimiter);
		free(current);
		current = next;
	}
}

void	free_commands(t_command *cmd)
{
	t_command	*tmp;
	int			i;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->args)
		{
			i = 0;
			while (tmp->args[i])
			{
				free(tmp->args[i]);
				i++;
			}
			free(tmp->args);
		}
		if (tmp->input_file)
			free(tmp->input_file);
		if (tmp->output_file)
			free(tmp->output_file);
		if (tmp->heredoc_list)
			free_heredoc_list(tmp->heredoc_list);
		free(tmp);
	}
}

void	free_lexer_list(t_lexer *lexer)
{
	t_lexer	*tmp;

	while (lexer)
	{
		tmp = lexer;
		lexer = lexer->next;
		if (tmp->str)
			free(tmp->str);
		free(tmp);
	}
}

void	free_tools(t_tools *tools)
{
	free_lexer_list(tools->lexer_list);
	free(tools->args);
}
