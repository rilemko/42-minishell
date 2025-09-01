/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_045.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 12:19:15 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_045() :
*	Parsing process of character '-'.
*
*/
void	ft_prs_process_045(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	ft_prs_process_default(lne);
	if (lne->seg.cmd.has_argument == FALSE)
		ft_tokenize(lne);
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) tkn;
	if (lne->seg.wait_separator == TRUE)
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (((lne->ptr.in_quotes == FALSE
				&& (lne->buffer[lne->index - 1] == TOKEN_009
					|| lne->buffer[lne->index - 1] == TOKEN_032))
			|| (lne->ptr.in_quotes == TRUE
				&& (lne->buffer[lne->index - 1] == TOKEN_034
					|| lne->buffer[lne->index - 1] == TOKEN_039)
				&& (lne->buffer[lne->index - 2] == TOKEN_009
					|| lne->buffer[lne->index - 2] == TOKEN_032)))
		&& ft_isalpha(lne->buffer[lne->index + 1]) == TRUE
		&& lne->ptr.following == 1 && lne->seg.rdr.read_comment == FALSE
		&& lne->seg.rdr.read_redirection_i == FALSE
		&& lne->seg.rdr.read_redirection_o == FALSE
		&& lne->seg.rdr.read_options == FALSE)
	{
		lne->seg.cmd.has_options = TRUE;
		ft_lstclear(&lne->seg.cmd.tpl.options, ft_free);
		lne->seg.rdr.read_options = TRUE;
	}
	else
	{
		lne->seg.cmd.has_options = FALSE;
		lne->seg.rdr.read_options = FALSE;
	}
}
