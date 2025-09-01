/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:59:19 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/30 13:41:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(t_cmd *cmd, t_exe *exec)
{
	if (cmd->has_heredoc == TRUE
		|| cmd->has_herestr == TRUE)
	{
		ft_write(exec->pipe_doc[1], cmd->heredoc);
		ft_close(exec->pipe_doc[0]);
		ft_close(exec->pipe_doc[1]);
	}
}
