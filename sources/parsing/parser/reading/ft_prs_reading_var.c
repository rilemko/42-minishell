/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 18:05:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_var() :
*
*/
void	ft_prs_reading_var(t_lne *lne, t_bool cut)
{
	lne->seg.cmd.has_variable = TRUE;
	if (cut == TRUE)
		lne->seg.rdr.read_variable = FALSE;
	ft_arg_add(&lne->seg.cmd.tpl.variable, &lne->seg.rdr.arg);
}
