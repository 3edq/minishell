/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:36:21 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 10:49:10 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_exit_status(int exit_code, int *status)
{
	int	sig;

	if (WIFSIGNALED(exit_code))
	{
		sig = WTERMSIG(exit_code);
		*status = 128 + sig;
		if (sig == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
	}
	else if (WIFEXITED(exit_code))
		*status = WEXITSTATUS(exit_code);
	else
		*status = 1;
}

static int	verify_command(t_command *cmd, char **path, int *status,
		char **envp)
{
	if (!cmd->args || !cmd->args[0])
	{
		ft_putstr_fd("Command not found\n", STDERR_FILENO);
		*status = 127;
		return (0);
	}
	*path = find_path(cmd->args[0], envp);
	if (!*path)
	{
		ft_putstr_fd(cmd->args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		*status = 127;
		return (0);
	}
	return (1);
}

void	execute_command(t_command *cmd, char ***envp, int *status)
{
	char	*path;
	pid_t	pid;
	int		exit_code;

	if (!verify_command(cmd, &path, status, *envp))
		return ;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(path, cmd->args, *envp);
		perror(cmd->args[0]);
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, &exit_code, 0);
		handle_exit_status(exit_code, status);
	}
	free(path);
}
