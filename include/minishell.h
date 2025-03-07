#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# include "../libft/libft.h"
# include "builtin.h"
# include "executer.h"
# include "lexer.h"
# include "parser.h"
# include <dirent.h>
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
# include <unistd.h>

typedef enum e_shell_state
{
	STATE_INTERACTIVE, // normal
	STATE_HEREDOC,     // heredoc now
	STATE_EXECUTING,   // command now
}								t_shell_state;

extern volatile t_shell_state	g_shell_state;

char							**copy_env(char **envp);
void							free_env(char **envp);
void							free_commands(t_command *cmd);
void							free_lexer_list(t_lexer *lexer);
void							free_tools(t_tools *tools);

void							setup_signal_handlers(void);

#endif
