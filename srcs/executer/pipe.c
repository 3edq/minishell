/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:25:38 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/17 22:25:41 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	child_process(t_command *cmd, char ***envp, int *status,
		int *pipe_fd)
{
	apply_heredoc(cmd);
	handle_redirections(cmd);
	if (cmd->next && !cmd->output_file)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	if (!cmd->args || !cmd->args[0])
		exit(0);
	if (is_builtin(cmd->args[0]))
		exit(execute_builtin(cmd, envp));
	else
		execute_command(cmd, envp, status);
	exit(*status);
}

static void	parent_process(int *pipe_fd, t_command *cmd)
{
	if (cmd->next)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
}

static int	count_and_execute_cmds(t_command *cmd, char ***envp, int *status)
{
	int			pipe_fd[2];
	pid_t		pid;
	t_command	*current;
	int			cmd_count;

	current = cmd;
	cmd_count = 0;
	while (current)
	{
		if (current->next && pipe(pipe_fd) == -1)
			return (perror("pipe"), *status = 1, -1);
		pid = fork();
		if (pid == 0)
			child_process(current, envp, status, pipe_fd);
		else if (pid > 0)
		{
			parent_process(pipe_fd, current);
			cmd_count++;
		}
		current = current->next;
	}
	return (cmd_count);
}

void	execute_pipeline(t_command *cmd, char ***envp, int *status)
{
	int	original_stdin;
	int	original_stdout;
	int	cmd_count;
	int	exit_code;
	int	i;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	if ((cmd_count = count_and_execute_cmds(cmd, envp, status)) < 0)
		return ;
	i = -1;
	while (i++ < cmd_count)
	{
		wait(&exit_code);
		if (WIFEXITED(exit_code))
			*status = WEXITSTATUS(exit_code);
		else if (WIFSIGNALED(exit_code))
			*status = 128 + WTERMSIG(exit_code);
		else
			*status = 1;
	}
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdin);
	close(original_stdout);
}
