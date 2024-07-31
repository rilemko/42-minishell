/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_124.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/22 18:33:37 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_124() :
*	Parsing process of character '|'.
*
*/
void	ft_prs_process_124(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if (lne->ptr.in_quotes == TRUE
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
	if (lne->ptr.in_quotes == FALSE
		&& (((lne->count == 0 || lne->seg.cmd.ope.exists == TRUE
					|| lne->seg.cmd.rio.has_pipe_i == TRUE)
				&& lne->seg.is_started == FALSE)
			|| lne->ptr.following > tkn->repeat_max
			|| lne->seg.rdr.read_delimiter == TRUE
			|| lne->seg.rdr.read_herestr == TRUE
			|| lne->seg.rdr.read_options == TRUE
			|| lne->seg.rdr.read_redirection_i == TRUE
			|| lne->seg.rdr.read_redirection_o == TRUE))
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->seg.is_started == TRUE)
	{
		lne->is_complete = FALSE;
		lne->seg.is_complete = TRUE;
		lne->seg.wait_separator = FALSE;
		if (lne->buffer[lne->index + 1] != TOKEN_124)
		{
			lne->index += -1;
			lne->seg.cmd.rio.exists = TRUE;
			lne->seg.cmd.rio.has_pipe_o = TRUE;
		}
	}
	else if (lne->buffer[lne->index - 1] == TOKEN_124)
	{
		lne->seg.cmd.ope.exists = TRUE;
		lne->seg.cmd.ope.has_operand_or = TRUE;
	}
	else if (lne->count > 0 && lne->buffer[lne->index + 1] != TOKEN_124)
	{
		lne->seg.cmd.rio.exists = TRUE;
		lne->seg.cmd.rio.has_pipe_i = TRUE;
	}
}
