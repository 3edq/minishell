#ifndef TOKENS_H
# define TOKENS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_lexer
{
	char			*str;
	int				token;
	int				i;
	struct s_lexer	*next;
}					t_lexer;

typedef struct s_tools
{
	char			*args;
	t_lexer			*lexer_list;
}					t_tools;

enum				e_token_type
{
	TOKEN_PIPE = 1,
	REDIR_OUT,
	REDIR_IN,
	APPEND_OUT,
	HEREDOC,
	TOKEN_WORD
};

int					token_reader(t_tools *tools);
int					add_lexer_node(char *str, int token, t_lexer **lexer_list);
int					is_space(char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					skip_spaces(char *str, int i);
int					count_quotes(int i, char *str);
t_lexer				*ft_lexernew(char *str, int token);
void				ft_lexer_back(t_lexer **lst, t_lexer *new);

#endif