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
