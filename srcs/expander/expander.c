/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:30:32 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:16:39 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	expand_dollar(t_expand_ctx *ctx)
{
	char	*temp;
	char	*new_result;

	ctx->i++;
	if (ctx->input[ctx->i] == '?')
	{
		temp = expand_exit_status(ctx->exit_status);
		if (!temp)
			return (free(ctx->result), ctx->result = NULL, 1);
		new_result = ft_strjoin(ctx->result, temp);
		free(temp);
		if (!new_result)
			return (free(ctx->result), ctx->result = NULL, 1);
		free(ctx->result);
		ctx->result = new_result;
		ctx->i++;
		return (2);
	}
	else if (ctx->input[ctx->i] == '$')
	{
		ctx->i++;
		return (2);
	}
	return (0);
}

static int	expand_variable_part(t_expand_ctx *ctx)
{
	char	var[256];
	char	*temp;
	char	*new_result;
	size_t	j;

	j = 0;
	while (ctx->input[ctx->i] && ((ft_strchr(" \t\n\"'",
					ctx->input[ctx->i]) == NULL)) && j < 255)
		var[j++] = ctx->input[ctx->i++];
	var[j] = '\0';
	temp = expand_variable(var);
	if (!temp && ctx->input[ctx->i] != '"' && ctx->input[ctx->i] != '\''
		&& !*ctx->result)
		return (free(ctx->result), ctx->result = NULL, 1);
	if (!*temp && ctx->input[ctx->i] != '"' && ctx->input[ctx->i] != '\''
		&& !*ctx->result)
		return (free(temp), 1);
	new_result = ft_strjoin(ctx->result, temp);
	free(temp);
	if (!new_result)
		return (free(ctx->result), ctx->result = NULL, 1);
	free(ctx->result);
	ctx->result = new_result;
	return (0);
}

static int	handle_expansion(t_expand_ctx *ctx)
{
	int	res;

	res = expand_dollar(ctx);
	if (res == 1)
		return (1);
	else if (res == 2)
		return (0);
	if (!(ctx->quote_state & 0b01) && expand_variable_part(ctx))
		return (1);
	return (0);
}

static int	process_character(t_expand_ctx *ctx)
{
	if (ctx->input[ctx->i] == '\'' || ctx->input[ctx->i] == '"')
	{
		if (toggle_quote(ctx->input[ctx->i], &ctx->quote_state))
			expand_character(&ctx->result, ctx->input[ctx->i]);
		ctx->i++;
		return (0);
	}
	if (ctx->input[ctx->i] == '$' && ctx->input[ctx->i + 1] && ctx->input[ctx->i
			+ 1] != '"' && ctx->input[ctx->i + 1] != ' '
		&& !(ctx->quote_state & 0b01))
	{
		return (handle_expansion(ctx));
	}
	else if (expand_character(&ctx->result, ctx->input[ctx->i++]))
		return (1);
	return (0);
}

char	*expand_string(const char *input, int exit_status)
{
	t_expand_ctx	ctx;

	ctx.quote_state = 0;
	ctx.result = ft_strdup("");
	if (!ctx.result)
		return (NULL);
	ctx.input = input;
	ctx.exit_status = exit_status;
	ctx.i = 0;
	while (input[ctx.i])
	{
		if (process_character(&ctx))
		{
			free(ctx.result);
			return (NULL);
		}
	}
	return (ctx.result);
}
