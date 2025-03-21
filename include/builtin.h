/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:09:42 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/18 12:01:40 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "parser.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
int		is_builtin(char *cmd);
int		execute_builtin(t_command *cmd, char ***envp);
int		builtin_exit(char **args);
int		builtin_pwd(void);
int		builtin_cd(char **args, char ***envp);
int		builtin_env(char **envp);

int		builtin_export(char ***envp, char *arg);
int		is_valid_identifier(const char *arg);
char	*get_key(const char *arg, int *append_mode);
void	sort_env(char **envp);
int		print_env(char **envp);
int		up_ex_env_util(char ***envp, int i, char *key);

int		builtin_unset(char ***envp, char *key);
int		builtin_echo(char **args);

#endif
