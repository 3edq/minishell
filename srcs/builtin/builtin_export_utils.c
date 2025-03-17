/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:18:28 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:18:56 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_valid_identifier(const char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (0);
	if (!(ft_isalpha(arg[0]) || arg[0] == '_'))
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!(ft_isalnum(arg[i]) || arg[i] == '_'))
		{
			if (arg[i] == '+' && arg[i + 1] == '=')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

char	*get_key(const char *arg, int *append_mode)
{
	char	*key;
	size_t	len;

	*append_mode = 0;
	len = 0;
	while (arg[len] != '=' && arg[len] != '\0')
	{
		if (arg[len] == '+' && arg[len + 1] == '=')
		{
			*append_mode = 1;
			break ;
		}
		len++;
	}
	key = ft_substr(arg, 0, len);
	if (!key)
		return (NULL);
	return (key);
}

void	sort_env(char **envp)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (envp[i] != NULL)
	{
		j = i + 1;
		while (envp[j] != NULL)
		{
			if (ft_strcmp(envp[i], envp[j]) > 0)
			{
				tmp = envp[i];
				envp[i] = envp[j];
				envp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	print_env(char **envp)
{
	int		i;
	char	*equal_pos;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		equal_pos = ft_strchr(envp[i], '=');
		if (equal_pos != NULL)
		{
			write(STDOUT_FILENO, envp[i], equal_pos - envp[i] + 1);
			ft_putchar_fd('"', STDOUT_FILENO);
			ft_putstr_fd(equal_pos + 1, STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
		else
			ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	return (0);
}

int	up_ex_env_util(char ***envp, int i, char *key)
{
	return (!ft_strncmp((*envp)[i], key, ft_strlen(key))
		&& ((*envp)[i][ft_strlen(key)] == '='
			|| (*envp)[i][ft_strlen(key)] == '\0'));
}
