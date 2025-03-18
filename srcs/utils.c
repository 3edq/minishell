/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:26:29 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 11:26:32 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**copy_env(char **envp)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

static void	expand_command_util(t_command *cmd, int exit_status)
{
	int		i;
	int		j;
	char	*expanded_arg;

	i = 0;
	while (cmd->args[i])
	{
		expanded_arg = expand_string(cmd->args[i], exit_status);
		if (!expanded_arg)
		{
			free(cmd->args[i]);
			j = i;
			while (cmd->args[j])
			{
				cmd->args[j] = cmd->args[j + 1];
				j++;
			}
			continue ;
		}
		free(cmd->args[i]);
		cmd->args[i] = expanded_arg;
		i++;
	}
}

int	expand_command(t_command *cmd_list, int exit_status)
{
	t_command	*cmd;

	cmd = cmd_list;
	while (cmd)
	{
		if (cmd->args)
		{
			expand_command_util(cmd, exit_status);
			if (cmd->args[0] == NULL)
			{
				free(cmd->args);
				cmd->args = NULL;
			}
		}
		cmd = cmd->next;
	}
	return (0);
}
