/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:10 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:07:29 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	itoa_exit_status(int exit_status, char *buffer)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	tmp = 0;
	if (exit_status == 0)
		buffer[i++] = '0';
	while (exit_status > 0)
	{
		buffer[i++] = (exit_status % 10) + '0';
		exit_status /= 10;
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
}

char	*expand_exit_status(int exit_status)
{
	char	buffer[12];
	char	*result;

	itoa_exit_status(exit_status, buffer);
	result = ft_strdup(buffer);
	if (!result)
		return (NULL);
	return (result);
}

int	toggle_quote(char c, int *quote_state)
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

int	expand_character(char **result, char c)
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
