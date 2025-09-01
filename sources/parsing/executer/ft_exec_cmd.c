/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:28:16 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/24 00:02:06 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_simple_cmd(t_app *app, t_exe *exe, t_lst *lst, size_t depth)
{
	t_pid	process_id;
	t_cmd	*cmd;

	cmd = ft_cmd_get(&lst, 0);
	if (cmd->is_builtins == TRUE && cmd->rio.exists == FALSE)
	{
		ft_simple_builtin(app, exe, cmd);
		ft_execute(app, exe, lst->next, depth);
	}
	else
	{
		process_id = ft_simple_cmd(app, exe, cmd);
		if (cmd->sub.is_ended == FALSE && cmd->rio.has_pipe_o == TRUE)
			ft_execute(app, exe, lst->next, depth);
		ft_set_exit_status(app, &process_id, exe);
		if (cmd->sub.is_ended == FALSE && cmd->rio.has_pipe_o == FALSE)
			ft_execute(app, exe, lst->next, depth);
	}
}
