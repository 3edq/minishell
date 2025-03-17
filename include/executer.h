/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:09:54 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:09:59 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H
# include "parser.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	judge_command_list(t_command *cmd_list, char ***envp, int *status);
void	execute_command(t_command *cmd, char ***envp, int *status);
char	*find_path(char *cmd, char **envp);
void	handle_redirections(t_command *cmd);
void	execute_pipeline(t_command *cmd, char ***envp, int *status);

#endif