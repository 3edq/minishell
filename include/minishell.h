#ifndef MINISHELL_H
# define MINISHELL_H

# define _DEFAULT_SOURCE

# include "../libft/libft.h"
# include "builtin.h"
# include "executer.h"
# include "lexer.h"
# include "parser.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

typedef enum e_shell_state {
	STATE_INTERACTIVE,
	STATE_HEREDOC,
	STATE_EXECUTING,
}	t_shell_state;

extern volatile t_shell_state g_shell_state;

void	process_all_heredocs(t_command *cmd_list);
char	**copy_env(char **envp);
void	free_env(char **envp);
void	free_commands(t_command *cmd);
void	free_lexer_list(t_lexer *lexer);
void	free_tools(t_tools *tools);
char	*generate_heredoc_filename(void);
void	process_all_heredocs(t_command *cmd_list);
void	apply_heredoc(t_command *cmd);
void	setup_signal_handlers();

#endif
