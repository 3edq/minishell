#include "../../include/minishell.h"

void	handle_redirections(t_command *cmd)
{
	int	fd;
	int	flags;

	if (cmd->input_file)
	{
		fd = open(cmd->input_file, O_RDONLY);
		if (fd == -1)
		{
			perror(cmd->input_file);
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (cmd->output_file)
	{
		if (cmd->append)
			flags = O_WRONLY | O_CREAT | O_APPEND;
		else
			flags = O_WRONLY | O_CREAT | O_TRUNC;
		fd = open(cmd->output_file, flags, 0644);
		if (fd == -1)
		{
			perror(cmd->output_file);
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	handle_heredoc_execution(t_command *cmd)
{
	int		pipefd[2];
	pid_t	pid;
	char	*line;
	int		status;

	if (!cmd->delimiter)
		return ;
	g_shell_state = STATE_HEREDOC;
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		signal(SIGINT, SIG_DFL);
		while (1)
		{
			line = readline("> ");
			if (!line || ft_strcmp(line, cmd->delimiter) == 0)
			{
				free(line);
				break ;
			}
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		close(pipefd[1]);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	g_shell_state = STATE_INTERACTIVE;
}
