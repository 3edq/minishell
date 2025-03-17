/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:30:23 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:30:26 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_overflow(const char *str)
{
	int		i;
	int		sign;
	long	num;
	long	digit;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		digit = str[i++] - '0';
		if ((sign == 1 && (num > (LONG_MAX / 10) || (num == (LONG_MAX / 10)
						&& digit > (LONG_MAX % 10)))) || (sign == -1
				&& (num > (LONG_MIN / -10) || (num == (LONG_MIN / -10)
						&& digit > (((LONG_MIN) % 10) * -1)))))
			return (1);
		num = num * 10 + digit;
	}
	return (0);
}

static long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	builtin_exit(char **args)
{
	long	exit_status;

	if (isatty(STDIN_FILENO))
		write(STDERR_FILENO, "exit\n", 5);
	if (!args[1])
		exit(0);
	if (!is_numeric(args[1]) || check_overflow(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(2);
	}
	exit_status = ft_atol(args[1]);
	if (args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	exit((unsigned char)exit_status);
}
