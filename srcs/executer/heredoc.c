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
	int			result;

	saved_stdin = dup(STDIN_FILENO);
	current = cmd_list;
	while (current)
	{
		heredoc_current = current->heredoc_list;
		while (heredoc_current)
		{
			result = handle_single_heredoc(heredoc_current);
			if (result)
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
			fprintf(stderr, "minishell: warning: here-document delimited by");
			fprintf(stderr, " end-of-file (wanted `%s')\n", delimiter);
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
	if (pipe(pipe_fds) == -1)
	{
		perror("pipe");
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		return (0);
	}
	if (pid == 0)
		handle_heredoc_child(pipe_fds, heredoc->delimiter);
	else
	{
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
	}
	return (0);
}
