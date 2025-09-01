/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:30:36 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/24 14:02:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_cmd(t_app *app, t_exe *exe, t_cmd *cmd)
{
	ft_pipe_redirection(app, cmd, exe);
	if (cmd->is_builtins == TRUE)
		ft_exit(app, ft_which_builtin(cmd, app), "");
	if (cmd->has_command == TRUE && ft_strlen(cmd->fullname) > 0)
	{
		if (cmd->exists == FALSE)
			ft_perror(app->name, cmd->terminal, "", "command not found");
		else
		{
			execve(cmd->fullname, ft_split(ft_strmjoin(ft_strmjoin
						(ft_strmjoin(ft_strjoin(cmd->fullname, " "),
								cmd->options), " "),
						cmd->argument), ' '),
				ft_lsttoarr(app->env));
			ft_perror(app->name, cmd->fullname, "", "");
			if (ft_is_xcutable(cmd->fullname, TRUE, FALSE) == FALSE)
				ft_exit(app, 126, "");
		}
		ft_exit(app, 127, "");
	}
	ft_exit(app, 0, "");
}
