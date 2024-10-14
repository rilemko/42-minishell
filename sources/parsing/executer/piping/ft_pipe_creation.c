/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:56:25 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/18 16:49:39 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_creation(t_exe *exec, t_cmd *cmd, t_app *app)
{
	(void)app;
	if (cmd->rio.has_pipe_o == TRUE)
	{
		if (pipe(exec->pipe_tab) == -1)
			perror("pipe creation error\n");
	}
	if (cmd->has_heredoc == TRUE || cmd->has_herestr == TRUE)
		pipe(exec->pipe_doc);
}
