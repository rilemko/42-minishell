/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:26:55 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/24 12:10:58 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_exit_status(t_app *app, t_pid *pid, t_exe *exe)
{
	waitpid(*pid, &exe->status, 0);
	if (WIFEXITED(exe->status))
		exe->exit_status = WEXITSTATUS(exe->status);
	else if (WIFSIGNALED(exe->status))
	{
		if (WTERMSIG(exe->status) == SIGBUS)
		{
			ft_perror("", "", "", "Bus error : 10");
			exe->exit_status = 138;
		}
		else if (WTERMSIG(exe->status) == SIGINT)
		{
			ft_write(STDOUT_FILENO, "\n");
			exe->exit_status = 130;
		}
		else if (WTERMSIG(exe->status) == SIGSEGV)
		{
			ft_perror("", "", "", "Segmentation fault");
			exe->exit_status = 139;
		}
	}
	ft_app_set_status(app, exe->exit_status);
}
