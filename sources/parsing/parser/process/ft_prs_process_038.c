/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_038.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 21:16:49 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_038() :
*	Parsing process of character '&'.
*
*/
void	ft_prs_process_038(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if ((lne->buffer[lne->index - 1] != TOKEN_038
			&& lne->buffer[lne->index + 1] != TOKEN_038)
		|| (lne->buffer[lne->index - 1] == TOKEN_038
			&& lne->buffer[lne->index - 2] == TOKEN_038)
		|| lne->ptr.in_quotes == TRUE
		|| lne->seg.rdr.read_comment == TRUE
		|| lne->seg.rdr.read_error == TRUE)
	{
		return (ft_prs_process_default(lne));
	}
	return (ft_tokenize(lne));
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	if (lne->ptr.in_quotes == FALSE
		&& (((lne->count == 0 || lne->seg.cmd.ope.exists == TRUE)
				&& lne->seg.is_started == FALSE)
			|| lne->ptr.following > tkn->repeat_max
			|| lne->seg.rdr.read_options == TRUE
			|| (lne->seg.rdr.is_started == FALSE
				&& (lne->seg.rdr.read_redirection_i == TRUE
					|| lne->seg.rdr.read_redirection_o == TRUE))))
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->buffer[lne->index + 1] == TOKEN_038
		&& lne->seg.is_started == TRUE)
	{
		lne->is_complete = FALSE;
		lne->seg.is_complete = TRUE;
		lne->seg.wait_separator = FALSE;
	}
	else if (lne->buffer[lne->index - 1] == TOKEN_038
		&& lne->seg.is_started == FALSE)
	{
		lne->seg.cmd.ope.exists = TRUE;
		lne->seg.cmd.ope.has_operand_and = TRUE;
	}
}
