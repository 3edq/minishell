#include "../include/minishell.h"

volatile int	g_shell_state = 0;

void	free_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

char	**copy_env(char **envp)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

void	free_heredoc_list(t_heredoc *heredoc_list)
{
	t_heredoc	*current;
	t_heredoc	*next;

	current = heredoc_list;
	while (current)
	{
		next = current->next;
		if (current->delimiter)
			free(current->delimiter);
		free(current);
		current = next;
	}
}

void	free_commands(t_command *cmd)
{
	t_command	*tmp;
	int			i;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->args)
		{
			i = 0;
			while (tmp->args[i])
			{
				free(tmp->args[i]);
				i++;
			}
			free(tmp->args);
		}
		if (tmp->input_file)
			free(tmp->input_file);
		if (tmp->output_file)
			free(tmp->output_file);
		if (tmp->heredoc_list)
			free_heredoc_list(tmp->heredoc_list);
		free(tmp);
	}
}

void	free_lexer_list(t_lexer *lexer)
{
	t_lexer	*tmp;

	while (lexer)
	{
		tmp = lexer;
		lexer = lexer->next;
		if (tmp->str)
			free(tmp->str);
		free(tmp);
	}
}

void	free_tools(t_tools *tools)
{
	free_lexer_list(tools->lexer_list);
	free(tools->args);
}

void	expand_command_util(t_command *cmd, int i, int j, int exit_status)
{
	char	*expanded_arg;

	while (cmd->args[i])
	{
		expanded_arg = expand_string(cmd->args[i], exit_status);
		if (!expanded_arg)
		{
			free(cmd->args[i]);
			j = i;
			while (cmd->args[j])
			{
				cmd->args[j] = cmd->args[j + 1];
				j++;
			}
			continue ;
		}
		free(cmd->args[i]);
		cmd->args[i] = expanded_arg;
		i++;
	}
}

void	expand_command(t_command *cmd_list, int exit_status)
{
	t_command	*cmd;
	int			i;
	int			j;

	cmd = cmd_list;
	while (cmd)
	{
		i = 0;
		if (cmd->args)
		{
			i = 0;
			j = 0;
			expand_command_util(cmd, i, j, exit_status);
			if (cmd->args[0] == NULL)
			{
				free(cmd->args);
				cmd->args = NULL;
			}
		}
		cmd = cmd->next;
	}
}

void	main_loop(t_tools tools, t_command *cmd_list, int *exit_status,
		char **my_envp)
{
	char	*input;

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
		if (!token_reader(&tools))
		{
			free(input);
			continue ;
		}
		cmd_list = parse_tokens(tools.lexer_list);
		if (!cmd_list)
		{
			free_tools(&tools);
			continue ;
		}
		expand_command(cmd_list, *exit_status);
		judge_command_list(cmd_list, &my_envp, exit_status);
		free_commands(cmd_list);
		free_tools(&tools);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		**my_envp;
	t_tools		tools;
	t_command	*cmd_list;
	int			last_exit_status;

	(void)argc;
	(void)argv;
	my_envp = copy_env(envp);
	last_exit_status = 0;
	tools.args = NULL;
	tools.lexer_list = NULL;
	cmd_list = NULL;
	setup_signal_handlers();
	main_loop(tools, cmd_list, &last_exit_status, my_envp);
	return (free_env(my_envp), last_exit_status);
}
