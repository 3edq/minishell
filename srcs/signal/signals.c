/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:18:28 by enkwak            #+#    #+#             */
/*   Updated: 2025/03/18 12:05:52 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_sigint(int signo)
{
	(void)signo;
	if (g_shell_state == 0)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_shell_state == 1)
	{
		write(1, "^C\n", 3);
		rl_replace_line("", 0);
	}
	else if (g_shell_state == 2)
	{
		write(1, "\n", 1);
	}
}

void	handle_sigquit(int signo)
{
	(void)signo;
	if (g_shell_state == 0 || g_shell_state == 1)
	{
		return ;
	}
	else if (g_shell_state == 2)
	{
		write(1, "Quit (core dumped)\n", 19);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_handler = handle_sigint;
	sa_int.sa_flags = SA_RESTART;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);
	if (g_shell_state == 0 || g_shell_state == 1)
	{
		signal(SIGQUIT, SIG_IGN);
	}
	else if (g_shell_state == 2)
	{
		sa_quit.sa_handler = handle_sigquit;
		sa_quit.sa_flags = SA_RESTART;
		sigemptyset(&sa_quit.sa_mask);
		sigaction(SIGQUIT, &sa_quit, NULL);
	}
}
