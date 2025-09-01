/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_cmt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 16:31:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_cmt() :
*
*/
void	ft_prs_reading_cmt(t_lne *lne, t_bool cut)
{
	lne->seg.rdr.read_comment = FALSE;
	if (cut == TRUE)
		lne->seg.cmd.has_comment = TRUE;
	ft_strlcat(lne->seg.cmd.comments, lne->seg.rdr.arg.content, MAX_PATH_SIZE);
}
