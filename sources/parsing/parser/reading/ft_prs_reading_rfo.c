/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_rfo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 18:13:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_rfo() :
*
*/
void	ft_prs_reading_rfo(t_lne *lne, t_bool cut)
{
	if (cut == TRUE)
	{
		lne->seg.rdr.read_redirection_o = FALSE;
		ft_chrcat(lne->seg.rdr.arg.content, '\25', MAX_LINE_SIZE);
	}
	ft_arg_add(&lne->seg.cmd.tpl.pathname_file_o, &lne->seg.rdr.arg);
}
