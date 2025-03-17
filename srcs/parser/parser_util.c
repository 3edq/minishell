/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:14:38 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/17 22:22:06 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"
#include "../include/parser.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;
		ft_memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}

int	handle_pipe(t_lexer **lexer, t_command **current)
{
	if ((*lexer)->token != TOKEN_PIPE)
		return (0);
	(*lexer) = (*lexer)->next;
	(*current)->next = new_command();
	if (!(*current)->next)
		return (0);
	(*current) = (*current)->next;
	return (1);
}

static int	handle_redir_out(t_lexer **lexer, t_command *current)
{
	int		fd;
	char	*new_file;

	if ((*lexer)->token != REDIR_OUT && (*lexer)->token != APPEND_OUT)
		return (0);
	if (!(*lexer)->next || (*lexer)->next->token != TOKEN_WORD)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
			2);
		return (-1);
	}
	new_file = ft_strdup((*lexer)->next->str);
	if (!new_file)
		return (-1);
	if (current->output_file)
	{
		fd = open(current->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd != -1)
			close(fd);
		free(current->output_file);
	}
	current->output_file = new_file;
	current->append = ((*lexer)->token == APPEND_OUT);
	*lexer = (*lexer)->next->next;
	return (1);
}

static int	handle_redir_in(t_lexer **lexer, t_command *current)
{
	if ((*lexer)->token != REDIR_IN)
		return (0);
	if ((*lexer)->next == NULL || (*lexer)->next->token != TOKEN_WORD)
	{
		fprintf(stderr,
			"Syntax error: expected file after input redirection\n");
		return (-1);
	}
	current->input_file = ft_strdup((*lexer)->next->str);
	if (!current->input_file)
		return (-1);
	*lexer = (*lexer)->next->next;
	return (1);
}

int	which_redirect(t_lexer **lexer_list, t_command *current)
{
	int	ret;

	ret = handle_heredoc(lexer_list, current);
	if (ret == -1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		return (-1);
	}
	if (ret == 1)
		return (1);
	ret = handle_redir_in(lexer_list, current);
	if (ret == -1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		return (-1);
	}
	if (ret == 1)
		return (1);
	ret = handle_redir_out(lexer_list, current);
	if (ret == -1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		return (-1);
	}
	return (ret);
}
