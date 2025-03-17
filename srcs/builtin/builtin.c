#include "../include/minishell.h"
#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_command *cmd, char ***envp)
{
	int			status;
	static char	**my_env;
	static int	sign = 0;
	int			status1;
	int			status2;

	if (sign++ == 0)
		my_env = copy_env(*envp);
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (builtin_cd(cmd->args, envp));
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
	{
		status = builtin_exit(cmd->args);
		if (status != 1)
			exit(status);
		return (status);
	}
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(cmd->args[0], "echo") == 0)
		return (builtin_echo(cmd->args));
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		return (builtin_env(my_env));
	else if (ft_strcmp(cmd->args[0], "export") == 0)
	{
		if (!cmd->args[1])
			return (builtin_export(envp, NULL));
		else
			return (builtin_export(envp, cmd->args[1]));
	}
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
	{
		if (cmd->args[1])
		{
			status1 = builtin_unset(envp, cmd->args[1]);
			status2 = builtin_unset(&my_env, cmd->args[1]);
			if (status1 != 0 || status2 != 0)
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (-1);
}
