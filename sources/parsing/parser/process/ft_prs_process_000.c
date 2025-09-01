/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_000.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 16:50:30 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);
static void	ft_tokenize_next(t_lne *lne);

/*
*	ft_prs_process_000() :
*	Parsing process of character '\0'.
*
*/
void	ft_prs_process_000(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	ft_parse_read(lne, lne->ptr.in_quotes == FALSE);
	if (lne->seg.rdr.read_error == FALSE)
		ft_tokenize(lne);
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) tkn;
	if ((lne->seg.rdr.is_started == FALSE
			&& (lne->seg.rdr.read_options == TRUE
				|| lne->seg.rdr.read_delimiter == TRUE
				|| (lne->seg.rdr.is_started == FALSE
					&& (lne->seg.rdr.read_redirection_i == TRUE
						|| lne->seg.rdr.read_redirection_o == TRUE)))))
	{
		ft_parse_abort(lne, TRUE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->ptr.in_quotes == TRUE
		|| (lne->heredoc > 0 && lne->ptr.current_depth == 0
			&& lne->ptr.in_quotes == FALSE && lne->seg.is_started == TRUE))
	{
		if (lne->buffer[lne->index - 1] != TOKEN_012)
			ft_chrcat(lne->buffer, TOKEN_012, ++lne->length + 1);
		lne->index += -1;
	}
	else if (lne->is_complete == FALSE)
	{
		ft_tokenize_next(lne);
	}
	lne->index += -1;
	lne->ptr.in_comment = FALSE;
	lne->seg.rdr.read_comment = FALSE;
	lne->seg.is_complete = lne->is_complete == TRUE;
	lne->sts.is_reading = FALSE;
}

static void	ft_tokenize_next(t_lne *lne)
{
	if (lne->ptr.current_depth == 0 && lne->seg.is_started == TRUE
		&& lne->heredoc == 0)
		lne->is_complete = TRUE;
	else if (lne->ptr.current_depth > 0 && lne->ptr.in_comment == FALSE)
	{
		ft_chrcat(lne->buffer, TOKEN_059, ++lne->length + 1);
		ft_chrcat(lne->buffer, TOKEN_032, ++lne->length + 1);
		lne->index += -1;
	}
	else if (lne->seg.rdr.read_heredoc == FALSE)
		ft_chrcat(lne->buffer, TOKEN_032, ++lne->length + 1);
}
