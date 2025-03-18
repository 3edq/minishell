/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:54:41 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/18 11:54:43 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*create_new_value(char *key, char *existing_value, char *new_val)
{
	char	*temp;
	char	*result;
	char	*joined_val;

	if (!existing_value)
		existing_value = "";
	joined_val = ft_strjoin(existing_value, new_val);
	if (!joined_val)
		return (NULL);
	temp = ft_strjoin(key, "=");
	if (!temp)
		return (free(joined_val), NULL);
	result = ft_strjoin(temp, joined_val);
	if (!result)
		return (free(temp), free(joined_val), NULL);
	free(temp);
	free(joined_val);
	return (result);
}

static int	update_existing_env(char ***envp, char *key, char *arg,
		int append_mode)
{
	int		i;
	char	*equal_pos;
	char	*existing_value;
	char	*new_entry;

	equal_pos = ft_strchr(arg, '=');
	i = -1;
	while ((*envp)[++i])
	{
		if (up_ex_env_util(envp, i, key))
		{
			if (append_mode && equal_pos)
			{
				existing_value = ft_strchr((*envp)[i], '=');
				if (existing_value)
					existing_value++;
				new_entry = create_new_value(key, existing_value, equal_pos
						+ 1);
			}
			else
				new_entry = ft_strdup(arg);
			return (free((*envp)[i]), (*envp)[i] = new_entry, 1);
		}
	}
	return (0);
}

static char	*prepare_new_value(char *key, char *arg, int append_mode)
{
	char	*equal_pos;
	char	*temp;
	char	*new_value;

	equal_pos = ft_strchr(arg, '=');
	if (append_mode && equal_pos)
	{
		temp = ft_strjoin(key, "=");
		if (!temp)
			return (NULL);
		new_value = ft_strjoin(temp, equal_pos + 1);
		free(temp);
	}
	else
		new_value = ft_strdup(arg);
	if (!new_value)
		return (NULL);
	return (new_value);
}

static int	add_to_env(char ***envp, char *key, char *arg, int append_mode)
{
	int		i;
	char	**new_env;
	char	*new_value;

	if (update_existing_env(envp, key, arg, append_mode))
		return (0);
	new_value = prepare_new_value(key, arg, append_mode);
	if (!new_value)
		return (1);
	i = 0;
	while ((*envp)[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (free(new_value), 1);
	i = -1;
	while ((*envp)[++i])
		new_env[i] = (*envp)[i];
	new_env[i] = new_value;
	new_env[i + 1] = NULL;
	free(*envp);
	*envp = new_env;
	return (0);
}

int	builtin_export(char ***envp, char *arg)
{
	char	*key;
	int		append_mode;
	int		result;

	if (arg == NULL)
	{
		sort_env(*envp);
		return (print_env(*envp));
	}
	if (!is_valid_identifier(arg))
	{
		ft_putstr_fd(" not a valid identifier\n", STDERR_FILENO);
		return (1);
	}
	key = get_key(arg, &append_mode);
	if (!key)
		return (1);
	result = add_to_env(envp, key, arg, append_mode);
	free(key);
	if (result)
		return (1);
	if (result == 0)
		sort_env(*envp);
	return (result);
}
