/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:36:31 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 17:24:40 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	judge_path(char *args, int *status)
{
	DIR	*dir;
	int	i;

	i = 0;
	while (args[i] && args[i] != ' ' && args[i] != '\t')
	{
		if (args[i] == '/' || args[i] == '.')
		{
			dir = opendir(args);
			if (dir)
			{
				closedir(dir);
				ft_putstr_fd("bash: ", STDERR_FILENO);
				ft_putstr_fd(args, STDERR_FILENO);
				ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
				*status = 126;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static void	exec_non_builtin(t_command *cmd, char ***envp, int *status)
{
	char	*cmd_path;

	cmd_path = find_path(cmd->args[0], *envp);
	if (cmd_path)
	{
		execute_command(cmd, envp, status);
		free(cmd_path);
	}
	else
	{
		ft_putstr_fd(cmd->args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		*status = 127;
	}
}

static void	execute_single_cmd(t_command *cmd, char ***envp, int *status)
{
	if (!cmd->args || !cmd->args[0])
	{
		*status = 0;
		return ;
	}
	if (judge_path(cmd->args[0], status))
		return ;
	if (is_builtin(cmd->args[0]))
		*status = execute_builtin(cmd, envp);
	else
		exec_non_builtin(cmd, envp, status);
}

void	judge_command_list(t_command *cmd_list, char ***envp, int *status)
{
	int	fds[2];

	g_shell_state = 2;
	if (!cmd_list->args && *status == 2)
	{
		g_shell_state = 0;
		return ;
	}
	if (process_all_heredocs(cmd_list, status))
		return ;
	if (cmd_list->next)
		execute_pipeline(cmd_list, envp, status);
	else
	{
		fds[0] = dup(STDIN_FILENO);
		fds[1] = dup(STDOUT_FILENO);
		handle_redirections(cmd_list);
		apply_heredoc(cmd_list);
		execute_single_cmd(cmd_list, envp, status);
		dup2(fds[0], STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		close(fds[1]);
	}
	g_shell_state = 0;
}
