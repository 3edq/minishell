/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:15:14 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 10:39:09 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	apply_heredoc_multi(t_command *cmd)
{
	t_heredoc	*current;
	t_heredoc	*last_heredoc;

	last_heredoc = cmd->heredoc_list;
	while (last_heredoc->next)
		last_heredoc = last_heredoc->next;
	if (last_heredoc && last_heredoc->fd > 0)
	{
		dup2(last_heredoc->fd, STDIN_FILENO);
		close(last_heredoc->fd);
		last_heredoc->fd = -1;
	}
	current = cmd->heredoc_list;
	while (current)
	{
		if (current != last_heredoc && current->fd > 0)
		{
			close(current->fd);
			current->fd = -1;
		}
		current = current->next;
	}
}

void	apply_heredoc(t_command *cmd)
{
	if (!cmd->heredoc_list)
		return ;
	if (!cmd->heredoc_list->next)
	{
		if (cmd->heredoc_list->fd > 0)
		{
			dup2(cmd->heredoc_list->fd, STDIN_FILENO);
			close(cmd->heredoc_list->fd);
			cmd->heredoc_list->fd = -1;
		}
		return ;
	}
	apply_heredoc_multi(cmd);
}

int	process_all_heredocs(t_command *cmd_list, int *status)
{
	t_command	*current;
	t_heredoc	*heredoc_current;
	int			saved_stdin;

	saved_stdin = dup(STDIN_FILENO);
	current = cmd_list;
	while (current)
	{
		heredoc_current = current->heredoc_list;
		while (heredoc_current)
		{
			if (handle_single_heredoc(heredoc_current))
			{
				dup2(saved_stdin, STDIN_FILENO);
				close(saved_stdin);
				*status = 130;
				return (1);
			}
			heredoc_current = heredoc_current->next;
		}
		current = current->next;
	}
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	return (0);
}
