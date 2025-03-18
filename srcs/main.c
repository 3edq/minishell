/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:26:09 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/03/18 18:14:46 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int	g_shell_state = 0;

void	process_command(t_tools *tools, t_command **cmd_list, char ***my_envp,
		int *last_exit_status)
{
	if (!token_reader(tools))
	{
		free(tools->args);
		return ;
	}
	*cmd_list = parse_tokens(tools->lexer_list, last_exit_status);
	if (!*cmd_list)
	{
		free_tools(tools);
		return ;
	}
	if (expand_command(*cmd_list, *last_exit_status))
		return ;
	judge_command_list(*cmd_list, my_envp, last_exit_status);
	free_commands(*cmd_list);
	free_tools(tools);
}

int	shell_loop(char ***my_envp, int *last_exit_status)
{
	char		*input;
	t_tools		tools;
	t_command	*cmd_list;

	while (1)
	{
		g_shell_state = 0;
		input = readline("minishell> ");
		if (!input)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (*input)
			add_history(input);
		tools.args = input;
		tools.lexer_list = NULL;
		process_command(&tools, &cmd_list, my_envp, last_exit_status);
	}
	free_env(*my_envp);
	return (*last_exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	char	**my_envp;
	int		last_exit_status;

	(void)argc;
	(void)argv;
	my_envp = copy_env(envp);
	last_exit_status = 0;
	setup_signal_handlers();
	return (shell_loop(&my_envp, &last_exit_status));
}
