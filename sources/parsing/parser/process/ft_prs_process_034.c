/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_034.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 19:45:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_034() :
*	Parsing process of character '''.
*
*/
void	ft_prs_process_034(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if (lne->ptr.in_quotes_double == TRUE
		|| lne->seg.rdr.read_comment == TRUE
		|| lne->seg.rdr.read_error == TRUE
		|| lne->seg.rdr.read_heredoc == TRUE)
	{
		return (ft_prs_process_default(lne));
	}
	return (ft_tokenize(lne));
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) lne;
	(void) tkn;
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->ptr.in_quotes == FALSE)
	{
		lne->is_complete = FALSE;
		lne->ptr.in_quotes = TRUE;
		lne->ptr.in_quotes_simple = TRUE;
		lne->seg.rdr.arg.in_quotes_simple = TRUE;
	}
	else if (lne->ptr.in_quotes_simple == TRUE)
	{
		if (lne->buffer[lne->index + 1] != TOKEN_012
			&& lne->buffer[lne->index + 1] != TOKEN_061)
			ft_parse_read(lne, lne->buffer[lne->index + 1] == TOKEN_009
				|| lne->buffer[lne->index + 1] == TOKEN_012
				|| lne->buffer[lne->index + 1] == TOKEN_032);
		if (lne->heredoc == 0 && lne->ptr.current_depth == 0
			&& lne->seg.rdr.read_heredoc == FALSE)
			lne->is_complete = TRUE;
		lne->ptr.in_quotes = FALSE;
		lne->ptr.in_quotes_simple = FALSE;
		lne->seg.rdr.arg.in_quotes_simple = TRUE;
	}
}
