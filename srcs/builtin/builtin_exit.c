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

// static int	is_numeric(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	if (!str[i])
// 		return (0);
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// static long	ft_atol(const char *str)
// {
// 	long	result;
// 	int		sign;
// 	int		i;

// 	result = 0;
// 	sign = 1;
// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i])
// 	{
// 		result = result * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (result * sign);
// }

// void	builtin_exit(char **args)
// {
// 	long	exit_status;

// 	write(1, "exit\n", 6);
// 	if (!args[1])
// 		exit(0);
// 	if (!is_numeric(args[1]))
// 	{
// 		fprintf(stderr, "minishell: exit: %s: numeric argument required\n", args[1]);
// 		exit(255);
// 	}
// 	exit_status = ft_atol(args[1]);
// 	if (exit_status > 9223372036854775807L || exit_status < -9223372036854775807L - 1)
// 	{
// 		fprintf(stderr, "minishell: exit: %s: numeric argument required\n", args[1]);
// 		exit(255);
// 	}
// 	if (args[2])
// 	{
// 		fprintf(stderr, "minishell: exit: too many arguments\n");
// 		return ;
// 	}
// 	exit((unsigned char)exit_status);
// }
