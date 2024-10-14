/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_060.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 16:59:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);
static void	ft_tokenize_next(t_lne *lne);

/*
*	ft_prs_process_060() :
*	Parsing process of character '<'.
*
*/
void	ft_prs_process_060(t_lne *lne, t_tkn *tkn)
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
				&& lne->seg.rdr.read_redirection_i == TRUE)
			|| lne->seg.wait_separator == TRUE
			|| lne->seg.rdr.read_redirection_o == TRUE))
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->seg.rdr.read_redirection_i == FALSE)
	{
		lne->is_complete = TRUE;
		lne->seg.cmd.has_heredoc = FALSE;
		lne->seg.cmd.rio.exists = TRUE;
		lne->seg.cmd.rio.has_file_i = TRUE;
		lne->seg.cmd.rio.has_pipe_i = FALSE;
		lne->seg.rdr.is_started = FALSE;
		lne->seg.rdr.read_redirection_i = TRUE;
		ft_bzero(lne->seg.rdr.arg.content, MAX_LINE_SIZE);
	}
	else
	{
		ft_tokenize_next(lne);
	}
}

static void	ft_tokenize_next(t_lne *lne)
{
	if (lne->seg.rdr.read_delimiter == FALSE)
	{
		lne->heredoc += 1;
		lne->is_complete = FALSE;
		lne->seg.cmd.has_heredoc = TRUE;
		lne->seg.cmd.has_herestr = FALSE;
		lne->seg.cmd.heredoc_count += 1;
		lne->seg.cmd.rio.has_file_i = FALSE;
		lne->seg.cmd.rio.has_pipe_i = TRUE;
		ft_lstclear(&lne->seg.cmd.tpl.heredoc, ft_free);
		lne->seg.rdr.read_delimiter = TRUE;
	}
	else if (lne->seg.rdr.read_delimiter == TRUE)
	{
		lne->heredoc += -1;
		lne->is_complete = TRUE;
		lne->seg.cmd.has_heredoc = FALSE;
		lne->seg.cmd.has_herestr = TRUE;
		lne->seg.cmd.heredoc_count += -1;
		lne->seg.rdr.read_delimiter = FALSE;
		lne->seg.rdr.read_herestr = TRUE;
	}
}
