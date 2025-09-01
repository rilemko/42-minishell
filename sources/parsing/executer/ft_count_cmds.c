/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:25:32 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:09:56 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_count_cmds(t_exe *exec, t_lst *cmd_list, size_t depth)
{
	t_cmd	*cmd;
	int		index;

	index = 0;
	cmd = ft_cmd_get(&cmd_list, index);
	while (cmd && cmd->sub.depth - cmd->sub.climb > depth)
		cmd = ft_cmd_get(&cmd_list, ++index);
	cmd = ft_cmd_get(&cmd_list, ++index);
	if (cmd && cmd->sub.depth >= depth)
		ft_execute(g_minishell, exec, ft_lstget(cmd_list, index), depth);
}
