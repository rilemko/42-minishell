/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_041.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 21:17:07 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_041() :
*	Parsing process of character ')'.
*
*/
void	ft_prs_process_041(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if ((lne->ptr.in_quotes == TRUE
			|| lne->seg.rdr.read_comment == TRUE
			|| lne->seg.rdr.read_error == TRUE)
		&& lne->sts.is_reading == TRUE)
	{
		return (ft_prs_process_default(lne));
	}
	return (ft_tokenize(lne));
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) tkn;
	if (lne->ptr.in_quotes == FALSE
		&& (lne->ptr.current_depth == 0
			|| (lne->seg.rdr.is_started == FALSE
				&& (lne->seg.rdr.read_redirection_i == TRUE
					|| lne->seg.rdr.read_redirection_o == TRUE))))
	{
		ft_parse_abort(lne, TRUE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	lne->ptr.current_depth += -1;
	if (lne->heredoc == 0 && lne->ptr.current_depth == 0)
		lne->is_complete = TRUE;
	lne->seg.wait_separator = TRUE;
	lne->seg.cmd.sub.climb += 1;
	lne->seg.cmd.sub.is_ended = TRUE;
}
