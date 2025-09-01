/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 16:30:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_cmd() :
*
*/
void	ft_prs_reading_cmd(t_lne *lne, t_bool cut)
{
	lne->seg.cmd.has_command = TRUE;
	if (cut == TRUE)
		lne->seg.rdr.read_command = FALSE;
	ft_arg_add(&lne->seg.cmd.tpl.fullname, &lne->seg.rdr.arg);
}
