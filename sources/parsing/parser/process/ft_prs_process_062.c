/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_062.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 18:13:22 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_062() :
*	Parsing process of character '>'.
*
*/
void	ft_prs_process_062(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if (lne->ptr.in_quotes == TRUE
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
		&& (lne->ptr.following > tkn->repeat_max
			|| (lne->ptr.following == 1
				&& lne->seg.rdr.read_redirection_o == TRUE)
			|| lne->seg.rdr.read_redirection_i == TRUE))
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->seg.rdr.read_redirection_o == FALSE)
	{
		lne->seg.cmd.rio.exists = TRUE;
		lne->seg.cmd.rio.file_append = FALSE;
		lne->seg.cmd.rio.has_file_o = TRUE;
		lne->seg.rdr.is_started = FALSE;
		lne->seg.rdr.read_redirection_o = TRUE;
		ft_bzero(lne->seg.rdr.arg.content, MAX_LINE_SIZE);
	}
	else if (lne->seg.cmd.rio.file_append == FALSE)
	{
		lne->seg.cmd.rio.file_append = TRUE;
	}
}
