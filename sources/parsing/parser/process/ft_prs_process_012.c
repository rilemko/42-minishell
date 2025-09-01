/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_012.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 23:33:45 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_012() :
*	Parsing process of character '\n'.
*
*/
void	ft_prs_process_012(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if (lne->ptr.in_quotes == TRUE
		|| lne->seg.rdr.read_error == TRUE
		|| lne->seg.rdr.read_heredoc == TRUE)
	{
		ft_prs_process_default(lne);
	}
	ft_parse_read(lne, lne->ptr.in_quotes == FALSE);
	ft_tokenize(lne);
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) lne;
	(void) tkn;
}

static void	ft_tokenize(t_lne *lne)
{
	lne->ptr.in_comment = FALSE;
	lne->seg.wait_separator = FALSE;
	lne->seg.rdr.read_comment = FALSE;
	if (lne->heredoc > 0)
	{
		if (lne->seg.is_started == TRUE && lne->seg.rdr.read_heredoc == FALSE)
		{
			lne->index += -1;
			lne->seg.is_complete = TRUE;
		}
		else
			lne->seg.rdr.read_heredoc = TRUE;
	}
	else
	{
		lne->seg.rdr.read_heredoc = FALSE;
		if (lne->ptr.current_depth == 0 && lne->ptr.in_quotes == FALSE)
			lne->is_complete = TRUE;
	}
}
