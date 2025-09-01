/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:28:18 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:47:36 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_simple_builtin(t_app *app, t_exe *exe, t_cmd *cmd)
{
	exe->exit_status = ft_which_builtin(cmd, app);
	ft_app_set_status(app, exe->exit_status);
	if (cmd->sub.is_ended == TRUE)
		exit(exe->exit_status);
}
