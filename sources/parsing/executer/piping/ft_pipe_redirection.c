/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:55:32 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 11:15:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_redirection(t_app *app, t_cmd *cmd, t_exe *exec)
{
	if (cmd->rio.has_file_i == TRUE)
		ft_change_infile(app, exec, cmd);
	if (cmd->rio.has_pipe_o == TRUE || cmd->rio.has_pipe_i == TRUE)
		ft_pipe_cmd(exec, cmd);
	else if (cmd->rio.has_file_i == FALSE && cmd->rio.has_pipe_i == FALSE)
	{
		ft_dup2(g_minishell->fds.fileno_std_i, STDIN_FILENO);
		exec->in_fd = dup(STDIN_FILENO);
	}
	if (cmd->rio.has_file_o == TRUE)
		ft_change_outfile(app, exec, cmd);
}
