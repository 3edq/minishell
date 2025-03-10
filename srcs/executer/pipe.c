#include "../../include/minishell.h"

static void child_process(t_command *cmd, char ***envp, int *status, int *pipe_fd)
{
	// ヒアドキュメントを適用
	apply_heredoc(cmd);
	
	handle_redirections(cmd);
	if (cmd->next && !cmd->output_file)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	if (is_builtin(cmd->args[0]))
		exit(execute_builtin(cmd, envp));
	else
		execute_command(cmd, envp, status);
	exit(*status);
}

// パイプラインの親プロセス処理
static void parent_process(pid_t pid, int *status, int *pipe_fd, t_command *cmd)
{
	int exit_code;

	if (cmd->next)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
	waitpid(pid, &exit_code, 0);
	if (WIFEXITED(exit_code))
		*status = WEXITSTATUS(exit_code);
	else
		*status = 1;
}

// パイプラインの実行
void execute_pipeline(t_command *cmd, char ***envp, int *status)
{
	int     pipe_fd[2];
	int     original_stdin;
	int     original_stdout;
	pid_t   pid;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	while (cmd)
	{
		if (cmd->next && pipe(pipe_fd) == -1)
		{
			perror("pipe");
			*status = 1;
			return;
		}
		pid = fork();
		if (pid == 0)
			child_process(cmd, envp, status, pipe_fd);
		else if (pid > 0)
			parent_process(pid, status, pipe_fd, cmd);
		cmd = cmd->next;
	}
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdin);
	close(original_stdout);
}
