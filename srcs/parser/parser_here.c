#include "../include/lexer.h"
#include "../include/parser.h"

static void	delete_quotes(char *str, char quote)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (str[0] != quote || str[len - 1] != quote || len < 2)
		return ;
	new_str = malloc(len - 1);
	if (!new_str)
		return ;
	i = 1;
	j = 0;
	while (i < len - 1)
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	ft_strlcpy(str, new_str, len);
	free(new_str);
}

void	add_heredoc(t_command *cmd, char *delimiter)
{
	t_heredoc	*new_doc;
	t_heredoc	*current;

	new_doc = malloc(sizeof(t_heredoc));
	if (!new_doc)
		return ;
	new_doc->delimiter = ft_strdup(delimiter);
	if (!new_doc->delimiter)
	{
		free(new_doc);
		return ;
	}
	new_doc->fd = -1;
	new_doc->next = NULL;
	if (!cmd->heredoc_list)
	{
		cmd->heredoc_list = new_doc;
		return ;
	}
	current = cmd->heredoc_list;
	while (current->next)
		current = current->next;
	current->next = new_doc;
}

int	handle_heredoc(t_lexer **lexer, t_command *current)
{
	char	*delimiter;

	if ((*lexer)->token != HEREDOC)
		return (0);
	if ((*lexer)->next == NULL || (*lexer)->next->token != TOKEN_WORD)
	{
		fprintf(stderr, "Syntax error: expected delimiter after <<\n");
		return (-1);
	}
	delimiter = ft_strdup((*lexer)->next->str);
	if (!delimiter)
		return (-1);
	if ((delimiter[0] == '"' && ft_strlen(delimiter) > 1
			&& delimiter[ft_strlen(delimiter) - 1] == '"')
		|| (delimiter[0] == '\'' && ft_strlen(delimiter) > 1
			&& delimiter[ft_strlen(delimiter) - 1] == '\''))
	{
		delete_quotes(delimiter, '"');
		delete_quotes(delimiter, '\'');
	}
	add_heredoc(current, delimiter);
	free(delimiter);
	*lexer = (*lexer)->next->next;
	return (1);
}
