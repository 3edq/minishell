#include "../../include/minishell.h"

void	apply_heredoc(t_command *cmd)
{
	if (cmd->heredoc_fd > 0)
	{
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		close(cmd->heredoc_fd);
		cmd->heredoc_fd = -1;
		if (cmd->heredoc_filename)
		{
			unlink(cmd->heredoc_filename);
			free(cmd->heredoc_filename);
			cmd->heredoc_filename = NULL;
		}
	}
}
char	*generate_heredoc_filename(void)
{
	static int	i = 0;
	char		*num;
	char		*filename;

	num = ft_itoa(i++);
	if (!num)
		return (NULL);
	filename = ft_strjoin("/tmp/minishell_heredoc_file_", num);
	free(num);
	return (filename);
}
void	handle_heredoc_execution(t_command *cmd)
{
	int		fd;
	pid_t	pid;
	char	*line;
	int		status;
	char	*tmp_filename;

	if (!cmd->delimiter)
		return ;
	g_shell_state = STATE_HEREDOC;
	tmp_filename = generate_heredoc_filename();
	if (!tmp_filename)
	{
		perror("generate_heredoc_filename");
		return ;
	}
	fd = open(tmp_filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		free(tmp_filename);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(fd);
		free(tmp_filename);
		return ;
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		while (1)
		{
			line = readline("> ");
			if (!line)
			{
				break ;
			}
			if (ft_strcmp(line, cmd->delimiter) == 0)
			{
				free(line);
				break ;
			}
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		close(fd);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd);
		fd = open(tmp_filename, O_RDONLY);
		if (fd == -1)
		{
			perror("open for reading");
			free(tmp_filename);
			return ;
		}
		cmd->heredoc_fd = fd;
		cmd->heredoc_filename = tmp_filename;
	}
	g_shell_state = STATE_INTERACTIVE;
}

void	process_all_heredocs(t_command *cmd_list)
{
	t_command	*tmp;
	int			saved_stdin;

	saved_stdin = dup(STDIN_FILENO);
	tmp = cmd_list;
	while (tmp)
	{
		if (tmp->delimiter)
			handle_heredoc_execution(tmp);
		tmp = tmp->next;
	}
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
}
