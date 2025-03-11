#include "../include/lexer.h"
#include "../include/parser.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

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
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
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
	if ((*lexer)->token != REDIR_OUT && (*lexer)->token != APPEND_OUT)
		return (0);
	if ((*lexer)->next == NULL || (*lexer)->next->token != TOKEN_WORD)
	{
		fprintf(stderr, "Syntax error: expected file after redirection\n");
		return (-1);
	}
	current->output_file = ft_strdup((*lexer)->next->str);
	if (!current->output_file)
		return (-1);
	if ((*lexer)->token == APPEND_OUT)
		current->append = 1;
	else
		current->append = 0;
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
		fprintf(stderr, "Error: Invalid heredoc redirection\n");
		return (-1);
	}
	if (ret == 1)
		return (1);
	ret = handle_redir_in(lexer_list, current);
	if (ret == -1)
	{
		fprintf(stderr, "Error: Invalid input redirection\n");
		return (-1);
	}
	if (ret == 1)
		return (1);
	ret = handle_redir_out(lexer_list, current);
	if (ret == -1)
	{
		fprintf(stderr, "Error: Invalid output redirection\n");
		return (-1);
	}
	if (ret == 1)
		return (1);
	return (0);
}
