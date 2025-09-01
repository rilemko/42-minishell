/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rdl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:25:05 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/14 23:26:32 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_rdl_creation(t_rdl *rdl);

void	st_rdl_clear(t_rdl *rdl)
{
	ft_free((void *) rdl->prompt_default);
	ft_free((void *) rdl->prompt_concate);
}

void	st_rdl_initialize(t_rdl *rdl)
{
	rdl->color_default = TERM_BCOLOR_CYA;
	rdl->color_concate = TERM_BCOLOR_BLU;
	rdl->prompt_default = "minishell$ ";
	rdl->prompt_concate = "> ";
	st_rdl_creation(rdl);
}

static void	st_rdl_creation(t_rdl *rdl)
{
	rdl->prompt_default = ft_strmjoin(ft_strjoin(rdl->color_default,
				rdl->prompt_default), TERMINAL_CRESET);
	rdl->prompt_concate = ft_strmjoin(ft_strjoin(rdl->color_concate,
				rdl->prompt_concate), TERMINAL_CRESET);
}
