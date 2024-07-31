/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_opt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 16:31:40 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_opt() :
*
*/
void	ft_prs_reading_opt(t_lne *lne, t_bool cut)
{
	lne->seg.cmd.has_options = TRUE;
	if (cut == TRUE)
		lne->seg.rdr.read_options = FALSE;
	ft_arg_add(&lne->seg.cmd.tpl.options, &lne->seg.rdr.arg);
}
