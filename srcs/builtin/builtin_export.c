#include "../include/minishell.h"

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

static char	*get_key(const char *arg, int *append_mode)
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
	return (key);
}

static void	sort_env(char **envp)
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

static int	print_env(char **envp)
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

int	builtin_export(char ***envp, char *arg)
{
	int		i;
	char	**new_env;
	char	*key;
	int		append_mode;
	char	*existing_value;
	char	*new_value;
	char	*equal_pos;
	char	*temp;

	if (arg == NULL)
	{
		sort_env(*envp);
		print_env(*envp);
		return (0);
	}
	if (!is_valid_identifier(arg))
	{
		ft_putstr_fd(" not a valid identifier\n", STDERR_FILENO);
		return (1);
	}
	key = get_key(arg, &append_mode);
	equal_pos = ft_strchr(arg, '=');
	i = 0;
	while ((*envp)[i] != NULL)
	{
		if (!ft_strncmp((*envp)[i], key, ft_strlen(key))
			&& ((*envp)[i][ft_strlen(key)] == '='
				|| (*envp)[i][ft_strlen(key)] == '\0'))
		{
			if (append_mode && equal_pos != NULL)
			{
				existing_value = ft_strchr((*envp)[i], '=');
				if (existing_value != NULL)
					existing_value++;
				else
					existing_value = "";
				new_value = ft_strjoin(existing_value, equal_pos + 1);
				temp = ft_strjoin(key, "=");
				free((*envp)[i]);
				(*envp)[i] = ft_strjoin(temp, new_value);
				free(temp);
				free(new_value);
			}
			else
			{
				free((*envp)[i]);
				(*envp)[i] = ft_strdup(arg);
			}
			free(key);
			sort_env(*envp);
			return (0);
		}
		i++;
	}
	if (append_mode && equal_pos != NULL)
	{
		temp = ft_strjoin(key, "=");
		new_value = ft_strjoin(temp, equal_pos + 1);
		free(temp);
	}
	else
		new_value = ft_strdup(arg);
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
	{
		free(key);
		free(new_value);
		return (1);
	}
	i = 0;
	while ((*envp)[i])
	{
		new_env[i] = (*envp)[i];
		i++;
	}
	// new_env[i] = ft_strdup(arg);
	new_env[i] = new_value;
	new_env[i + 1] = NULL;
	free(*envp);
	*envp = new_env;
	free(key);
	sort_env(*envp);
	return (0);
}

// char	*ft_strtok(char *str, const char *delim)
// {
// 	static char	*saved_str;
// 	char		*token_start;
// 	char		*delim_pos;

// 	if (str)
// 		saved_str = str;
// 	if (!saved_str || *saved_str == '\0')
// 		return (NULL);
// 	while (*saved_str && ft_strchr(delim, *saved_str))
// 		saved_str++;
// 	if (*saved_str == '\0')
// 		return (NULL);
// 	token_start = saved_str;
// 	delim_pos = saved_str;
// 	while (*delim_pos && !ft_strchr(delim, *delim_pos))
// 		delim_pos++;
// 	if (*delim_pos)
// 	{
// 		*delim_pos = '\0';
// 		saved_str = delim_pos + 1;
// 	}
// 	else
// 		saved_str = NULL;
// 	return (token_start);
// }

// static int	is_valid_identifier(const char *arg)
// {
// 	int	i;

// 	if (!arg || !arg[0])
// 		return (0);
// 	if (!(ft_isalpha(arg[0]) || arg[0] == '_'))
// 		return (0);
// 	i = 1;
// 	while (arg[i] && arg[i] != '=')
// 	{
// 		if (!(ft_isalnum(arg[i]) || arg[i] == '_'))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	builtin_export(char ***envp, char *arg)
// {
// 	int		i;
// 	char	**new_env;
// 	char	*key;
// 	size_t	len;
// 	int		append_mode;

// 	if (!is_valid_identifier(arg))
// 	{
// 		ft_putstr_fd(" not a valid identifier\n", STDERR_FILENO);
// 		return (1);
// 	}
// 	append_mode = 0;
// 	key = ft_strtok(arg, "=");
// 	len = ft_strlen(key);
// 	i = 0;
// 	while ((*envp)[i])
// 	{
// 		if (!ft_strncmp((*envp)[i], key, len) && (*envp)[i][len] == '=')
// 			return (free((*envp)[i]), (*envp)[i] = ft_strdup(arg), 0);
// 		i++;
// 	}
// 	new_env = malloc(sizeof(char *) * (i + 2));
// 	if (!new_env)
// 		return (1);
// 	i = 0;
// 	while ((*envp)[i])
// 	{
// 		new_env[i] = (*envp)[i];
// 		i++;
// 	}
// 	new_env[i] = ft_strdup(arg);
// 	new_env[i + 1] = NULL;
// 	free(*envp);
// 	*envp = new_env;
// 	return (0);
// }
