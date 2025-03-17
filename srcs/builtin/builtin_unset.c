/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:03:59 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:09:31 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	find_env_key(char **envp, char *key)
{
	int		i;
	size_t	len;

	len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if ((ft_strncmp(envp[i], key, len) == 0 && envp[i][len] == '=')
			|| ft_strcmp(envp[i], key) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void	create_new_env(char ***envp, int key_index, char **new_env)
{
	int	j;

	j = 0;
	while ((*envp)[j])
	{
		if (j == key_index)
		{
			free((*envp)[j]);
			j++;
			continue ;
		}
		if (j < key_index)
			new_env[j] = (*envp)[j];
		else
			new_env[j - 1] = (*envp)[j];
		j++;
	}
	new_env[j - 1] = NULL;
	free(*envp);
	*envp = new_env;
}

int	builtin_unset(char ***envp, char *key)
{
	int		i;
	int		env_count;
	char	**new_env;

	i = find_env_key(*envp, key);
	if (i == -1)
		return (0);
	env_count = 0;
	while ((*envp)[env_count])
		env_count++;
	new_env = malloc(sizeof(char *) * env_count);
	if (!new_env)
		return (1);
	create_new_env(envp, i, new_env);
	return (0);
}
