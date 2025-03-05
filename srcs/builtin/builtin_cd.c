#include "minishell.h"

static void	update_env(char ***envp, const char *key, const char *value)
{
	int		i;
	char	**new_env;
	char	*tmp;
	char	*new_entry;

	i = 0;
	while ((*envp)[i])
	{
		if (!ft_strncmp((*envp)[i], key, ft_strlen(key))
			&& (*envp)[i][ft_strlen(key)] == '=')
		{
			tmp = ft_strjoin(key, "=");
			new_entry = ft_strjoin(tmp, value);
			free(tmp);
			free((*envp)[i]);
			(*envp)[i] = new_entry;
			return ;
		}
		i++;
	}
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return ;
	i = 0;
	while ((*envp)[i])
	{
		new_env[i] = (*envp)[i];
		i++;
	}
	tmp = ft_strjoin(key, "=");
	new_entry = ft_strjoin(tmp, value);
	free(tmp);
	new_env[i] = new_entry;
	new_env[i + 1] = NULL;
	free(*envp);
	*envp = new_env;
}

int	builtin_cd(char **args, char ***envp)
{
	char	*old_pwd;
	char	*new_pwd;

	if (args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	if (!args[1])
	{
		ft_putstr_fd("minishell: cd: missing argument\n", STDERR_FILENO);
		return (1);
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		perror("minishell: cd: getcwd failed");
		return (1);
	}
	if (chdir(args[1]) != 0)
	{
		perror("minishell: cd");
		free(old_pwd);
		return (1);
	}
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		update_env(envp, "PWD", new_pwd);
		update_env(envp, "OLDPWD", old_pwd);
		free(new_pwd);
	}
	else
		perror("minishell: cd: failed to update PWD");
	free(old_pwd);
	return (0);
}
