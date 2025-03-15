#include "minishell.h"

// char	*expand_variable(const char *var)
// {
// 	char	*value;

// 	value = getenv(var);
// 	if (!value)
// 		return (ft_strdup(""));
// 	return (ft_strdup(value));
// }

char	*expand_variable(const char *var_name)
{
	char	*value;
	char	*expanded;

	value = getenv(var_name);
	if (!value)
		expanded = ft_strdup("");
	else
		expanded = ft_strdup(value);
	if (!expanded)
		return (NULL);
	return (expanded);
}

char	*expand_exit_status(int exit_status)
{
	char	buffer[12];
	int		i;
	int		num;
	char	*result;
	int		len;
	char	tmp;

	num = exit_status;
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	buffer[i] = '\0';
	len = i;
	i = 0;
	while (i < len / 2)
	{
		tmp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = tmp;
		i++;
	}
	result = ft_strdup(buffer);
	if (!result)
		return (NULL);
	return (result);
}

static int	toggle_quote(char c, int *quote_state)
{
	if (c == '\'')
	{
		if (*quote_state & 0b10)
			return (1);
		*quote_state ^= 0b01;
	}
	else if (c == '"')
	{
		if (*quote_state & 0b01)
			return (1);
		*quote_state ^= 0b10;
	}
	return (0);
}

static int	expand_character(char **result, char c)
{
	char	ch[2];
	char	*temp;

	ch[0] = c;
	ch[1] = '\0';
	temp = ft_strjoin(*result, ch);
	if (!temp)
	{
		free(*result);
		*result = NULL;
		return (1);
	}
	free(*result);
	*result = temp;
	return (0);
}

static int	expand_dollar(char **result, const char *input, size_t *i,
		int exit_status)
{
	char	*temp;
	char	*new_result;

	(*i)++;
	if (input[*i] == '?')
	{
		temp = expand_exit_status(exit_status);
		if (!temp)
			return (free(*result), *result = NULL, 1);
		new_result = ft_strjoin(*result, temp);
		free(temp);
		if (!new_result)
			return (free(*result), *result = NULL, 1);
		free(*result);
		*result = new_result;
		(*i)++;
		return (2);
	}
	else if (input[*i] == '$')
	{
		(*i)++;
		return (2);
	}
	return (0);
}

static int	expand_variable_part(char **result, const char *input, size_t *i)
{
	char	var[256];
	char	*temp;
	char	*new_result;
	size_t	j;

	j = 0;
	while (input[*i] && ((ft_strchr(" \t\n\"'", input[*i]) == NULL)) && j < 255)
		var[j++] = input[(*i)++];
	var[j] = '\0';
	temp = expand_variable(var);
	// if (!temp || !*temp)
	// 	return (free(*result), *result = NULL, 1);
	if (!temp)
		return (free(*result), *result = NULL, 1);
	if (!*temp) // temp が空文字列でも free する
	{
		free(temp);
		return (1);
	}
	new_result = ft_strjoin(*result, temp);
	free(temp);
	if (!new_result)
		return (free(*result), *result = NULL, 1);
	free(*result);
	*result = new_result;
	return (0);
}

static int	handle_expansion(char **result, const char *input, size_t *i,
		int exit_status, int quote_state)
{
	int	res;

	res = expand_dollar(result, input, i, exit_status);
	if (res == 1)
		return (1);
	else if (res == 2)
		return (0);
	if (!(quote_state & 0b01) && expand_variable_part(result, input, i))
		return (1);
	return (0);
}

static int	process_character(char **result, const char *input, size_t *i,
		int exit_status, int *quote_state)
{
	if (input[*i] == '\'' || input[*i] == '"')
	{
		if (toggle_quote(input[*i], quote_state))
			expand_character(result, input[*i]);
		(*i)++;
		return (0);
	}
	if (input[*i] == '$' && input[*i + 1] && input[*i + 1] != '"'
		&& !(*quote_state & 0b01))
	{
		return (handle_expansion(result, input, i, exit_status, *quote_state));
	}
	else if (expand_character(result, input[(*i)++]))
		return (1);
	return (0);
}

char	*expand_string(const char *input, int exit_status)
{
	char	*result;
	size_t	i;
	int		quote_state;

	quote_state = 0;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (process_character(&result, input, &i, exit_status, &quote_state))
		{
			free(result);
			return (NULL);
		}
	}
	return (result);
}
