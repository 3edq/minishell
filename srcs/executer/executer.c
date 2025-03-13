#include "../../include/minishell.h"

void	judge_command_list(t_command *cmd_list, char ***envp, int *status)
{
	char	*cmd_path;
	int		original_stdin;
	int		original_stdout;

	g_shell_state = STATE_EXECUTING;
	if (process_all_heredocs(cmd_list, status))
	{
		return ;
	}
	if (cmd_list->next)
	{
		execute_pipeline(cmd_list, envp, status);
	}
	else
	{
		original_stdin = dup(STDIN_FILENO);
		original_stdout = dup(STDOUT_FILENO);
		handle_redirections(cmd_list);
		apply_heredoc(cmd_list);
		if (!cmd_list->args || !cmd_list->args[0])
		{
			*status = 0;
			return ;
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
	int		sig;

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
	free(path);
}
