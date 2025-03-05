#include "../include/minishell.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saved_str;
	char		*token_start;
	char		*delim_pos;

	if (str)
		saved_str = str;
	if (!saved_str || *saved_str == '\0')
		return (NULL);
	while (*saved_str && ft_strchr(delim, *saved_str))
		saved_str++;
	if (*saved_str == '\0')
		return (NULL);
	token_start = saved_str;
	delim_pos = saved_str;
	while (*delim_pos && !ft_strchr(delim, *delim_pos))
		delim_pos++;
	if (*delim_pos)
	{
		*delim_pos = '\0';
		saved_str = delim_pos + 1;
	}
	else
		saved_str = NULL;
	return (token_start);
}

int	builtin_export(char ***envp, char *arg)
{
	int		i;
	char	**new_env;
	char	*key;
	size_t	len;

	if (!arg || !ft_strchr(arg, '='))
		return (ft_putstr_fd("minishell: export: invalid argument\n",
				STDERR_FILENO), 1);
	key = ft_strtok(arg, "=");
	len = ft_strlen(key);
	i = 0;
	while ((*envp)[i])
	{
		if (!ft_strncmp((*envp)[i], key, len) && (*envp)[i][len] == '=')
			return (free((*envp)[i]), (*envp)[i] = ft_strdup(arg), 0);
		i++;
	}
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (1);
	i = 0;
	while ((*envp)[i])
	{
		new_env[i] = (*envp)[i];
		i++;
	}
	new_env[i] = ft_strdup(arg);
	new_env[i + 1] = NULL;
	free(*envp);
	*envp = new_env;
	return (0);
}
