/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:15:04 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 12:06:39 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static pid_t	heredoc_fork(int pipe_fds[2])
{
	pid_t	pid;

	if (pipe(pipe_fds) == -1)
	{
		perror("pipe");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		return (-1);
	}
	return (pid);
}

static void	print_heredoc_warning(char *delimiter)
{
	ft_putstr_fd("bash: warning: here-document ", 2);
	ft_putstr_fd("at line 1 delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
}

static void	handle_heredoc_child(int *pipe_fds, char *delimiter)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	close(pipe_fds[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			print_heredoc_warning(delimiter);
			break ;
		}
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fds[1], line, ft_strlen(line));
		write(pipe_fds[1], "\n", 1);
		free(line);
	}
	close(pipe_fds[1]);
	exit(0);
}

int	handle_single_heredoc(t_heredoc *heredoc)
{
	int		pipe_fds[2];
	pid_t	pid;
	int		status;

	if (!heredoc || !heredoc->delimiter)
		return (0);
	g_shell_state = 1;
	pid = heredoc_fork(pipe_fds);
	if (pid == -1)
		return (0);
	if (pid == 0)
		handle_heredoc_child(pipe_fds, heredoc->delimiter);
	close(pipe_fds[1]);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(pipe_fds[0]);
		g_shell_state = 0;
		return (1);
	}
	heredoc->fd = pipe_fds[0];
	g_shell_state = 0;
	return (0);
}
