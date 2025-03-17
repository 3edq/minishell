/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:41:32 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/17 21:47:18 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

int	count_quotes(int i, char *str)
{
	char	quote;
	int		j;

	if (!str[i])
		return (0);
	quote = str[i];
	j = 1;
	while (str[i + j])
	{
		if (str[i + j] == quote)
			return (j + 1);
		j++;
	}
	return (-1);
}

int	get_token_type(int c)
{
	if (c == '|')
		return (TOKEN_PIPE);
	else if (c == '>')
		return (REDIR_OUT);
	else if (c == '<')
		return (REDIR_IN);
	return (0);
}

int	parse_special_token(char *str, int i, t_lexer **lexer_list)
{
	int	token;

	token = get_token_type(str[i]);
	if (token == REDIR_OUT && get_token_type(str[i + 1]) == REDIR_OUT)
	{
		if (!add_lexer_node(NULL, APPEND_OUT, lexer_list))
			return (-1);
		return (2);
	}
	else if (token == REDIR_IN && get_token_type(str[i + 1]) == REDIR_IN)
	{
		if (!add_lexer_node(NULL, HEREDOC, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_lexer_node(NULL, token, lexer_list))
			return (-1);
		return (1);
	}
	return (0);
}

int	parse_word_token(char *str, int i, t_lexer **lexer_list)
{
	int		j;
	int		quote_len;
	char	*word;

	j = 0;
	while (str[i + j] && !get_token_type(str[i + j]) && !is_space(str[i + j]))
	{
		if (str[i + j] == '"' || str[i + j] == '\'')
		{
			quote_len = count_quotes(i + j, str);
			if (quote_len < 0)
			{
				ft_putstr_fd("Error: closing quote not found.\n", 2);
				return (-1);
			}
			j += quote_len;
		}
		else
			j++;
	}
	word = ft_substr(str, i, j);
	if (!word || !add_lexer_node(word, TOKEN_WORD, lexer_list))
		return (free(word), -1);
	return (j);
}

int	token_reader(t_tools *tools)
{
	int	i;
	int	j;

	i = 0;
	while (tools->args[i])
	{
		j = 0;
		i = skip_spaces(tools->args, i);
		if (get_token_type(tools->args[i]))
			j = parse_special_token(tools->args, i, &tools->lexer_list);
		else
			j = parse_word_token(tools->args, i, &tools->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
