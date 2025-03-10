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

char	*find_path(char *cmd, char **envp)
{
	char **paths;
	char *path;
	int i;
	char *path_env;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (cmd[0] == '/' || (cmd[0] == '.' && (cmd[1] == '/' || cmd[1] == '.')))
		return (build_path(NULL, cmd));
	path_env = getenv("PATH");
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp)
		path_env = *envp + 5;
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = build_path(paths[i], cmd);
		if (path)
		{
			free_tab(paths);
			return (path);
		}
		i++;
	}
	free_tab(paths);
	return (NULL);
}
