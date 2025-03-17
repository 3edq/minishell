/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:10:18 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:10:20 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_env_entry(const char *key, const char *value)
{
	char	*tmp;
	char	*new_entry;

	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	new_entry = ft_strjoin(tmp, value);
	if (!new_entry)
		return (free(tmp), NULL);
	free(tmp);
	return (new_entry);
}

static int	update_env(char ***envp, const char *key, const char *value)
{
	int		i;
	char	**new_env;
	char	*new_entry;

	i = 0;
	while ((*envp)[i])
	{
		if (!ft_strncmp((*envp)[i], key, ft_strlen(key))
			&& (*envp)[i][ft_strlen(key)] == '=')
		{
			new_entry = create_env_entry(key, value);
			if (!new_entry)
				return (1);
			return (free((*envp)[i]), (*envp)[i] = new_entry, 0);
		}
		i++;
	}
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (1);
	ft_memcpy(new_env, *envp, sizeof(char *) * i);
	new_env[i] = create_env_entry(key, value);
	new_env[i + 1] = NULL;
	return (free(*envp), *envp = new_env, 0);
}

static char	*get_cd_path(char **args)
{
	char	*path;

	if (!args[1])
	{
		path = getenv("HOME");
		if (!path || !path[0])
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			return (NULL);
		}
		return (path);
	}
	return (args[1]);
}

static int	change_directory(char *path, char **old_pwd)
{
	*old_pwd = getcwd(NULL, 0);
	if (!*old_pwd)
	{
		perror("minishell: cd: getcwd failed");
		return (1);
	}
	if (chdir(path) != 0)
	{
		perror("minishell: cd");
		free(*old_pwd);
		*old_pwd = NULL;
		return (1);
	}
	return (0);
}

int	builtin_cd(char **args, char ***envp)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*path;

	if (args[1] && args[2])
		return (ft_putstr_fd("minishell: cd: too many arguments\n",
				STDERR_FILENO), 1);
	path = get_cd_path(args);
	if (!path)
		return (1);
	if (change_directory(path, &old_pwd) != 0)
		return (1);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		if (update_env(envp, "PWD", new_pwd))
			return (free(old_pwd), 1);
		if (update_env(envp, "OLDPWD", old_pwd))
			return (1);
		free(new_pwd);
	}
	else
		perror("minishell: cd: failed to update PWD");
	return (free(old_pwd), 0);
}
