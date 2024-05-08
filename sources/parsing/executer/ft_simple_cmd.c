/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:28:47 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:47:38 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	ft_simple_cmd(t_app *app, t_exe *exe, t_cmd *cmd)
{
	t_pid	pid;

	ft_pipe_creation(exe, cmd, app);
	ft_fork(&pid);
	if (pid == 0)
		ft_execute_cmd(app, exe, cmd);
	ft_heredoc(cmd, exe);
	ft_pipe_close(exe, cmd);
	return (pid);
}
