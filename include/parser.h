/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:44 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:10:48 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "lexer.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_heredoc
{
	char				*delimiter;
	int					fd;
	int					type;
	struct s_heredoc	*next;
}						t_heredoc;

typedef struct s_command
{
	char				**args;
	char				*input_file;
	char				*output_file;
	t_heredoc			*heredoc_list;
	int					append;
	struct s_command	*next;
}						t_command;

t_command				*parse_tokens(t_lexer *lexer_list);
void					free_commands(t_command *cmd);
int						handle_pipe(t_lexer **lexer, t_command **current);
int						which_redirect(t_lexer **lexer_list,
							t_command *current);
void					*ft_realloc(void *ptr, size_t old_size,
							size_t new_size);
t_command				*new_command(void);
void					add_heredoc(t_command *cmd, char *delimiter);
int						handle_heredoc(t_lexer **lexer, t_command *current);

#endif
