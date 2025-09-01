/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:56:42 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/23 21:54:20 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit_args(t_app *app)
{
	ft_write(STDOUT_FILENO, "exit\n");
	ft_perror(app->name, "exit", "", "too many arguments");
	ft_app_set_status(app, 1);
	app->sts.is_xcuting = FALSE;
	return (1);
}

int	ft_check_char(t_cmd *cmd)
{
	int	i;

	i = 0;
	if ((cmd->argument[0] == '-' || cmd->argument[0] == '+')
		&& ft_strlen(cmd->argument) != 1)
		i++;
	while (cmd->argument[i] != ' ' && cmd->argument[i] != '\0')
	{
		if (ft_isdigit(cmd->argument[i]) == TRUE)
			i++;
		else
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_exit_numeric_arg(t_cmd *cmd)
{
	if (ft_check_char(cmd) == SUCCESS)
	{
		if (ft_strlen(cmd->argument) > 20)
			return (FAILURE);
		else if (ft_strlen(cmd->argument) <= 20)
		{
			if (ft_strncmp(cmd->argument, "9223372036854775807",
					20) > 0)
				return (FAILURE);
			else if (cmd->argument[0] == '-')
			{
				if (ft_strncmp(cmd->argument, "-9223372036854775808",
						21) > 0)
					return (FAILURE);
			}
			else
				return (SUCCESS);
		}
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void	ft_exit_modulo(t_app *app, long long int exit_arg)
{
	if (exit_arg < 0)
		exit_arg *= -1;
	ft_app_set_status(app, exit_arg % 256);
}

int	ft_exit_builtin(t_app *app, t_cmd *cmd)
{
	long long	exit_arg;
	char		*error;

	exit_arg = ft_atoi(cmd->argument);
	if (ft_strcnt(cmd->argument, ' ') > 1 && ft_check_char(cmd) == SUCCESS)
		return (ft_exit_args(app));
	if (ft_strlen(cmd->argument) == 0)
		ft_app_set_status(app, app->last_status);
	else if (ft_exit_numeric_arg(cmd) == FAILURE)
	{
		error = ft_substr(cmd->argument, 0, ft_strpos(cmd->argument, ' '));
		ft_perror(app->name, "exit", error, "numeric argument required");
		ft_app_set_status(app, 255);
		ft_app_abort(app);
		ft_free((void *) error);
		return (255);
	}
	else if (0 <= exit_arg && exit_arg <= 255)
		ft_app_set_status(app, exit_arg);
	else if (exit_arg < -255 || exit_arg > 255)
		ft_exit_modulo(app, exit_arg);
	else if (-255 <= exit_arg && exit_arg < 0)
		ft_app_set_status(app, (256 - (exit_arg * -1)));
	ft_app_abort(app);
	return (exit_arg);
}
