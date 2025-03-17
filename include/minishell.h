/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:10:32 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:28:01 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _DEFAULT_SOURCE

# include "../libft/libft.h"
# include "builtin.h"
# include "executer.h"
# include "lexer.h"
# include "parser.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

extern volatile int	g_shell_state;

typedef struct s_expand_ctx
{
	char			*result;
	const char		*input;
	size_t			i;
	int				exit_status;
	int				quote_state;
}					t_expand_ctx;

int					process_all_heredocs(t_command *cmd_list, int *status);
int					handle_single_heredoc(t_heredoc *heredoc);
char				**copy_env(char **envp);
void				free_env(char **envp);
void				free_commands(t_command *cmd);
void				free_lexer_list(t_lexer *lexer);
void				free_tools(t_tools *tools);
void				apply_heredoc(t_command *cmd);
void				setup_signal_handlers(void);

char				*expand_string(const char *input, int exit_status);
char				*expand_variable(const char *var_name);
void				itoa_exit_status(int exit_status, char *buffer);
char				*expand_exit_status(int exit_status);
int					toggle_quote(char c, int *quote_state);
int					expand_character(char **result, char c);

#endif
