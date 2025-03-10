#include "../../include/minishell.h"

void	apply_heredoc(t_command *cmd)
{
	if (cmd->heredoc_fd > 0)
	{
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		close(cmd->heredoc_fd);
		cmd->heredoc_fd = -1;
	}
}

void	handle_heredoc_execution(t_command *cmd)
{
	int		pipe_fds[2];
	pid_t	pid;
	char	*line;
	int		status;

	if (!cmd->delimiter)
		return ;
	g_shell_state = STATE_HEREDOC;
	if (pipe(pipe_fds) == -1)
	{
		perror("pipe");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		return ;
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		close(pipe_fds[0]);
		while (1)
		{
			line = readline("> ");
			if (!line)
			{
				fprintf(stderr,
					"minishell: warning: here-document delimited by");
				fprintf(stderr, " end-of-file (wanted `%s')\n", cmd->delimiter);
				break ;
			}
			if (ft_strcmp(line, cmd->delimiter) == 0)
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
	else
	{
		close(pipe_fds[1]);
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		{
			close(pipe_fds[0]);
			return ;
		}
		cmd->heredoc_fd = pipe_fds[0];
	}
	g_shell_state = STATE_INTERACTIVE;
}
