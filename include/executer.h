#ifndef EXECUTER_H
# define EXECUTER_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "parser.h"

void	judge_command_list(t_command *cmd_list, char ***envp, int *status);
void	execute_command(t_command *cmd, char ***envp, int *status);
char	*find_path(char *cmd, char **envp);
void	handle_redirections(t_command *cmd);
void	execute_pipeline(t_command *cmd, char ***envp, int *status);
void	handle_heredoc_execution(t_command *cmd);

#endif