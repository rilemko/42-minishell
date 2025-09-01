/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:57:47 by vpolojie          #+#    #+#             */
/*   Updated: 2024/03/30 17:02:26 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export_no_opt(t_cmd *cmd, char **args, char **env)
{
	if (cmd->has_options == TRUE)
	{
		ft_free_deep((void **) args);
		ft_free_deep((void **) env);
		cmd->builtin_status = FALSE;
		ft_perror("minishell", "export", "", "no options allowed");
		return (FAILURE);
	}
	return (SUCCESS);
}

void	ft_set_arg_value(char *argument, char **var, char *buffer, t_app *app)
{
	int		index;
	t_arg	arg;

	index = ft_strpos(argument, '=');
	ft_interpret_normalize(ft_strchr(argument, '=') + 1);
	var = (char **) malloc(sizeof(char *) * 3);
	var[0] = ft_substr(argument, 0, index);
	var[1] = ft_substr(argument, index + 1,
			(ft_strlen(argument) - ft_strlen(var[0])));
	var[2] = NULL;
	st_arg_initialize(&arg);
	ft_strlcpy(arg.content, var[1], MAX_LINE_SIZE);
	ft_interpret_asterisk(&arg, buffer);
	ft_env_set(&app->env, var[0], buffer, TRUE);
	ft_free_deep((void **) var);
}

void	ft_set_export_arg(char *arg, t_app *app, t_cmd *cmd)
{
	char	**var;
	char	buffer[MAX_LINE_SIZE];

	var = NULL;
	ft_bzero(buffer, MAX_LINE_SIZE);
	if (ft_check_arg(arg) == SUCCESS)
	{
		if (ft_strpos(arg, '=') != -1)
			ft_set_arg_value(arg, var, buffer, app);
		else
			ft_env_add(&app->env, arg,
				ft_var_get(&app->var, arg, ""), FALSE);
	}
	else
	{
		cmd->builtin_status = FALSE;
		ft_perror(app->name, "export", arg, "not a valid identifier");
	}
}

int	ft_export(t_cmd *cmd, t_app *app, char **env, char *arg)
{
	char	**args;
	int		i;

	if (cmd->options[0] == ' ')
		ft_strlcat(arg, cmd->options, MAX_LINE_SIZE);
	args = ft_split(arg, ' ');
	i = 0;
	if (cmd->has_argument == FALSE
		&& ft_export_no_opt(cmd, args, env) == FAILURE)
		return (2);
	if (ft_strlen(arg) == 0 && cmd->has_options == FALSE)
		ft_export_env(cmd, env);
	else
	{
		while (args[i] != 0)
			ft_set_export_arg(args[i++], app, cmd);
	}
	ft_free_deep((void **) args);
	ft_free_deep((void **) env);
	return (ft_ternary_int(cmd->builtin_status == TRUE, 0, 1));
}
