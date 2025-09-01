/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 16:31:02 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_arg() :
*
*/
void	ft_prs_reading_arg(t_lne *lne, t_bool cut)
{
	lne->seg.cmd.has_argument = TRUE;
	if (cut == TRUE)
		lne->seg.count++;
	ft_arg_add(&lne->seg.cmd.tpl.argument, &lne->seg.rdr.arg);
}
