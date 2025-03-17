/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:18:59 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/17 22:19:02 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_input_file(t_command *cmd)
{
	int	fd;

	fd = open(cmd->input_file, O_RDONLY);
	if (fd == -1)
	{
		perror(cmd->input_file);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	handle_redirections(t_command *cmd)
{
	int	fd;
	int	flags;

	if (cmd->input_file)
		handle_input_file(cmd);
	if (cmd->output_file)
	{
		flags = O_WRONLY | O_CREAT;
		if (cmd->append)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		fd = open(cmd->output_file, flags, 0644);
		if (fd == -1)
		{
			perror(cmd->output_file);
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}
