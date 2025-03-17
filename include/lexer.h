/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:10 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:13:46 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
int					skip_spaces(char *str, int i);
t_lexer				*ft_lexernew(char *str, int token);
void				ft_lexer_back(t_lexer **lst, t_lexer *new);

#endif