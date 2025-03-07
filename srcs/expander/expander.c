#include "../include/lexer.h"
#include "../include/parser.h"
#include "minishell.h"

char	*expand_variable(const char *var)
{
	char	*value;

	value = getenv(var);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
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
	return (result);
}

char	*expand_string(const char *input, int exit_status)
{
	char	*result;
	char	*temp;
	size_t	i;
	char	var[256];
	size_t	j;
	char	ch[2];
	int		s_quote;
	int		d_quote;

	s_quote = 0;
	d_quote = 0;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] == '"' && !s_quote)
		{
			d_quote = !d_quote;
			i++;
			continue ;
		}
		else if (input[i] == '\'' && !d_quote)
		{
			s_quote = !s_quote;
			i++;
			continue ;
		}
		if (input[i] == '$' && (input[i + 1] && input[i + 1] != '"')
			&& ((d_quote && !s_quote) || (!d_quote && !s_quote)))
		{
			i++;
			if (input[i] == '?')
			{
				temp = expand_exit_status(exit_status);
				if (!temp)
				{
					free(result);
					return (NULL);
				}
				result = ft_strjoin(result, temp);
				if (!result)
				{
					free(temp);
					return (NULL);
				}
				free(temp);
				i++;
			}
			else if (input[i] == '$')
				i++;
			else
			{
				j = 0;
				while (input[i] && (ft_strchr(" \t\n\"'", input[i]) == NULL)
							&& j < 255)
					var[j++] = input[i++];
				var[j] = '\0';
				temp = expand_variable(var);
				if (!temp || !*temp)
				{
					free(result);
					return (NULL);
				}
				result = ft_strjoin(result, temp);
				if (!result)
				{
					free(temp);
					return (NULL);
				}
				free(temp);
			}
		}
		else
		{
			ch[0] = input[i];
			ch[1] = '\0';
			temp = ft_strjoin(result, ch);
			if (!temp)
			{
				free(result);
				return (NULL);
			}
			free(result);
			result = temp;
			i++;
		}
	}
	return (result);
}
