#include "../include/minishell.h"

int	builtin_exit(char **args)
{
	int	exit_status;

	if (args[1])
	{
		exit_status = ft_atoi(args[1]);
		if (exit_status == 0 && args[1][0] != '0')
		{
			ft_putstr_fd("minishell: exit: numeric argument required\n",
				STDERR_FILENO);
			exit(255);
		}
		exit(exit_status);
	}
	exit(0);
}
