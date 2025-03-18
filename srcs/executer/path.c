/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:28:54 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/17 22:28:57 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static char	*build_path(char *dir, char *cmd)
{
	char	*path;
	char	*full_path;

	if (!dir)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path = ft_strjoin(dir, "/");
	if (!path)
		return (NULL);
	full_path = ft_strjoin(path, cmd);
	free(path);
	if (full_path && access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

static char *try_path(char **paths, char *cmd)
{
   char    *path;
   int     i;


   i = 0;
   while (paths[i])
   {
       path = build_path(paths[i], cmd);
       if (path && access(path, X_OK) == 0)
       {
           free_tab(paths);
           return (path);
       }
       free(path);
       i++;
   }
   free_tab(paths);
   return (NULL);
}


char    *find_path(char *cmd, char **envp)
{
   char    **paths;
   char    *path_env;


   if (!cmd || cmd[0] == '\0')
       return (NULL);
   if (cmd[0] == '/' || (cmd[0] == '.' && (cmd[1] == '/' || cmd[1] == '.')))
       return (build_path(NULL, cmd));
   path_env = NULL;
   while (*envp)
   {
       if (ft_strncmp(*envp, "PATH=", 5) == 0)
       {
           path_env = *envp + 5;
           break ;
       }
       envp++;
   }
   if (!path_env || path_env[0] == '\0')
       return (NULL);
   paths = ft_split(path_env, ':');
   if (!paths)
       return (NULL);
   return (try_path(paths, cmd));
}

