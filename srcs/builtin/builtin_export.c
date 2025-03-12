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

static int	is_valid_identifier(const char *arg)
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
			return (0);
		i++;
	}
	return (1);
}

int	builtin_export(char ***envp, char *arg)
{
	int		i;
	char	**new_env;
	char	*key;
	size_t	len;
	int		append_mode;

	if (!is_valid_identifier(arg))
	{
		ft_putstr_fd(" not a valid identifier\n", STDERR_FILENO);
		return (1);
	}
	append_mode = 0;
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
