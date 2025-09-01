/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:08:21 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:48:11 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_cmd(t_exe *exec, t_cmd *cmd)
{
	if (cmd->rio.has_pipe_i == TRUE)
	{
		if (cmd->has_heredoc == TRUE || cmd->has_herestr == TRUE)
		{
			ft_dup2(exec->pipe_doc[0], STDIN_FILENO);
			ft_close(exec->pipe_doc[0]);
			ft_close(exec->pipe_doc[1]);
		}
		else
		{
			ft_dup2(exec->in_fd, STDIN_FILENO);
		}
	}
	if (cmd->rio.has_pipe_o == TRUE)
	{
		if (cmd->sub.is_ended == TRUE)
		{
			ft_dup2(exec->pipe_sub[1], STDOUT_FILENO);
		}
		else if (ft_dup2(exec->pipe_tab[1], STDOUT_FILENO) == FAILURE)
			perror("dup error in pipe out");
		ft_close(exec->pipe_tab[0]);
		ft_close(exec->pipe_tab[1]);
	}
}
