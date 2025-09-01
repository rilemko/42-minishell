/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:07:05 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/24 01:13:26 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_app *app, t_exe *exe, t_lst *lst, size_t depth)
{
	t_cmd	*cmd;

	if (lst == NULL || app->sts.is_xcuting == FALSE)
		return ;
	cmd = ft_cmd_get(&lst, 0);
	if (cmd->sub.depth > depth)
		return (ft_execute_sub(app, exe, lst, depth));
	ft_interpret(app, cmd);
	if (ft_check_last_status(exe, cmd) == FAILURE)
	{
		if (cmd->sub.is_ended == FALSE)
			return (ft_execute(app, exe, lst->next, depth));
		else
			return ;
	}
	ft_execute_simple_cmd(app, exe, lst, depth);
}

void	ft_execute_sub(t_app *app, t_exe *exe, t_lst *lst, size_t depth)
{
	t_pid	process_id;
	t_cmd	*cmd;

	cmd = ft_cmd_get(&lst, 0);
	if (ft_check_last_status(exe, cmd) == FAILURE)
	{
		ft_count_cmds(exe, lst, depth);
		return ;
	}
	pipe(exe->pipe_sub);
	ft_fork(&process_id);
	if (process_id == 0)
	{
		ft_execute(app, exe, lst, depth + 1);
		exit(exe->exit_status);
	}
	ft_set_exit_status(app, &process_id, exe);
	ft_set_and_close(exe, lst, depth);
}
