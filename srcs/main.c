#include "../include/minishell.h"

volatile t_shell_state g_shell_state = STATE_INTERACTIVE;

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

int	expand_command(t_command *cmd_list, int exit_status)
{
    t_command		*cmd;
    int				i;
    char			*expanded_arg;

    cmd = cmd_list;
    while (cmd)
    {
        i = 0;
        while (cmd->args && cmd->args[i])
        {
            expanded_arg = expand_string(cmd->args[i], exit_status);
            if (!expanded_arg)
                return (1);
            free(cmd->args[i]);
            cmd->args[i] = expanded_arg;
            i++;
        }
        cmd = cmd->next;
    }
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char		**my_envp;
	char		*input;
	t_tools		tools;
	t_command	*cmd_list;
	int			last_exit_status;

	(void)argc;
	(void)argv;
	my_envp = copy_env(envp);
	last_exit_status = 0;
	setup_signal_handlers();
	while (1)
	{
		g_shell_state = STATE_INTERACTIVE;
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
			fprintf(stderr, "トークン解析エラー\n");
			free(input);
			continue ;
		}
		cmd_list = parse_tokens(tools.lexer_list);
		if (!cmd_list)
		{
			fprintf(stderr, "パースエラー\n");
			free_tools(&tools);
			continue ;
		}
		if (expand_command(cmd_list, last_exit_status))
			continue ;
		judge_command_list(cmd_list, &my_envp, &last_exit_status);
		free_commands(cmd_list);
		free_tools(&tools);
	}
	free_env(my_envp);
	return (last_exit_status);
}
