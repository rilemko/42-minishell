/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:00:05 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/19 15:58:28 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_which_builtin(t_cmd *cmd, t_app *app)
{
	if (ft_strncmp(cmd->basename, "export", 7) == 0)
		return (ft_export(cmd, app, ft_lsttoarr(app->env), cmd->argument));
	else
	{
		ft_interpret_normalize(cmd->argument);
		if (ft_strncmp(cmd->basename, "cd", 3) == 0)
			return (ft_cd(app, cmd->argument));
		if (ft_strncmp(cmd->basename, "echo", 5) == 0)
			return (ft_echo(cmd, cmd->argument, cmd->options));
		if (ft_strncmp(cmd->basename, "env", 4) == 0)
			return (ft_env_builtin(cmd, ft_lsttoarr(app->env)));
		if (ft_strncmp(cmd->basename, "pwd", 4) == 0)
			return (ft_pwd(cmd, app));
		if (ft_strncmp(cmd->basename, "unset", 6) == 0)
			return (ft_unset(cmd, app, cmd->argument));
		if (ft_strncmp(cmd->basename, "exit", 5) == 0)
			return (ft_exit_builtin(app, cmd));
	}
	return (1);
}
