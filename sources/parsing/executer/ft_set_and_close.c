/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_and_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:27:29 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:47:31 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_and_close(t_exe *exe, t_lst *lst, size_t depth)
{
	exe->in_fd = dup(exe->pipe_sub[0]);
	close(exe->pipe_sub[0]);
	close(exe->pipe_sub[1]);
	ft_count_cmds(exe, lst, depth);
	close(exe->in_fd);
}
