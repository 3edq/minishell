#include "../include/minishell.h"

int	builtin_unset(char ***envp, char *key)
{
	int		i;
	int		j;
	size_t	len;
	char	**new_env;

	len = ft_strlen(key);
	i = 0;
	while ((*envp)[i])
	{
		if (!ft_strncmp((*envp)[i], key, len) && (*envp)[i][len] == '=')
			break ;
		i++;
	}
	if (!(*envp)[i])
		return (1);
	free((*envp)[i]);
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		return (1);
	j = 0;
	while ((*envp)[j])
	{
		if (j != i)
			new_env[j - (j > i)] = (*envp)[j];
		j++;
	}
	new_env[j - 1] = NULL;
	free(*envp);
	*envp = new_env;
	return (0);
}
