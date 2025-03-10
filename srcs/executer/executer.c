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

void	prepare_heredoc(t_command *cmd)
{
	int		fd;
	pid_t	pid;
	char	*line;
	int		status;

	if (!cmd->delimiter)
		return ;
	cmd->heredoc_file = generate_heredoc_filename();
	if (!cmd->heredoc_file)
	{
		perror("generate_heredoc_filename");
		return ;
	}
	fd = open(cmd->heredoc_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		free(cmd->heredoc_file);
		cmd->heredoc_file = NULL;
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		while (1)
		{
			line = readline("> ");
			if (!line)
				break ;
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
	}
}

void judge_command_list(t_command *cmd_list, char ***envp, int *status)
{
	char *cmd_path;
	int original_stdin;
	int original_stdout;

	g_shell_state = STATE_EXECUTING;
	
	// すべてのヒアドキュメントを事前処理
	process_all_heredocs(cmd_list);
	
	if (cmd_list->next)
	{
		// パイプラインの場合
		execute_pipeline(cmd_list, envp, status);
	}
	else
	{
		// 単一コマンドの場合
		original_stdin = dup(STDIN_FILENO);
		original_stdout = dup(STDOUT_FILENO);
		
		handle_redirections(cmd_list);
		apply_heredoc(cmd_list);
		
		if (!cmd_list->args || !cmd_list->args[0])
		{
			fprintf(stderr, "Error: Invalid command\n");
			*status = 127;
			return;
		}
		
		if (is_builtin(cmd_list->args[0]))
			*status = execute_builtin(cmd_list, envp);
		else
		{
			cmd_path = find_path(cmd_list->args[0], *envp);
			if (cmd_path)
			{
				execute_command(cmd_list, envp, status);
				free(cmd_path);
			}
			else
			{
				ft_putstr_fd(cmd_list->args[0], STDERR_FILENO);
				ft_putstr_fd(": command not found\n", STDERR_FILENO);
				*status = 127;
			}
		}
		
		dup2(original_stdin, STDIN_FILENO);
		dup2(original_stdout, STDOUT_FILENO);
		close(original_stdin);
		close(original_stdout);
	}
	
	g_shell_state = STATE_INTERACTIVE;
}
void	execute_command(t_command *cmd, char ***envp, int *status)
{
	char	*path;
	pid_t	pid;
	int		exit_code;

	if (!cmd->args || !cmd->args[0])
	{
		ft_putstr_fd("Command not found\n", STDERR_FILENO);
		*status = 127;
		return ;
	}
	path = find_path(cmd->args[0], *envp);
	if (!path)
	{
		ft_putstr_fd(cmd->args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		*status = 127;
		return ;
	}
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
		if (WIFSIGNALED(exit_code))
		{
			if (WTERMSIG(exit_code) == SIGQUIT)
				ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
		}
		else if (WIFEXITED(exit_code))
			*status = WEXITSTATUS(exit_code);
		else
			*status = 1;
	}
	free(path);
}
