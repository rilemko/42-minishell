/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/13 22:04:29 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_str() :
*
*/
void	ft_prs_reading_str(t_lne *lne, t_bool cut)
{
	if (cut == TRUE)
	{
		ft_chrcat(lne->seg.rdr.arg.content, TOKEN_012, MAX_LINE_SIZE);
		lne->seg.rdr.read_herestr = FALSE;
		lne->seg.rdr.read_redirection_i = FALSE;
	}
	ft_arg_add(&lne->seg.cmd.tpl.heredoc, &lne->seg.rdr.arg);
}
