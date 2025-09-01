/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_exe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:14:33 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 23:11:10 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_exe_clear(t_exe *exe)
{
	(void) exe;
}

void	st_exe_initialize(t_exe *exe)
{
	exe->exit_status = 0;
	exe->file_out = FAILURE;
	exe->in_fd = FAILURE;
	exe->skip = FALSE;
	exe->status = 0;
}
