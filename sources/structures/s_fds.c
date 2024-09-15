/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:40:53 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 18:12:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_fds_creation(t_fds *fds);
static void	st_fds_precheck(t_app *app);

void	st_fds_clear(t_fds *fds)
{
	ft_close(fds->fileno_std_e);
	ft_close(fds->fileno_std_i);
	ft_close(fds->fileno_std_o);
}

void	st_fds_initialize(t_fds *fds, t_app *app)
{
	st_fds_precheck(app);
	fds->fileno_std_e = -1;
	fds->fileno_std_i = -1;
	fds->fileno_std_o = -1;
	st_fds_creation(fds);
}

static void	st_fds_creation(t_fds *fds)
{
	fds->fileno_std_e = ft_dup(STDERR_FILENO);
	fds->fileno_std_i = ft_dup(STDIN_FILENO);
	fds->fileno_std_o = ft_dup(STDOUT_FILENO);
}

static void	st_fds_precheck(t_app *app)
{
	if (ft_isatty(STDERR_FILENO) != SUCCESS
		|| ft_isatty(STDIN_FILENO) != SUCCESS
		|| ft_isatty(STDOUT_FILENO) != SUCCESS)
		ft_exit_failure(app, "");
}
