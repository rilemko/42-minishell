/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_default.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 12:20:30 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne);
static void	ft_tokenize(t_lne *lne);

void	ft_prs_process_default(t_lne *lne)
{
	ft_precheck(lne);
	ft_tokenize(lne);
}

static void	ft_precheck(t_lne *lne)
{
	if (lne->seg.wait_separator == TRUE
		&& lne->seg.rdr.read_redirection_o == FALSE)
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	lne->seg.is_started = TRUE;
	lne->seg.cmd.id = lne->count;
	lne->seg.cmd.sub.depth = lne->ptr.current_depth;
	lne->seg.rdr.is_started = TRUE;
	if (lne->buffer[lne->index] == TOKEN_032
		&& lne->ptr.in_quotes == TRUE
		&& lne->seg.rdr.read_command == FALSE
		&& lne->seg.rdr.read_comment == FALSE
		&& lne->seg.rdr.read_delimiter == FALSE
		&& lne->seg.rdr.read_error == FALSE
		&& lne->seg.rdr.read_herestr == FALSE
		&& lne->seg.rdr.read_options == FALSE
		&& lne->seg.rdr.read_redirection_i == FALSE
		&& lne->seg.rdr.read_redirection_o == FALSE)
		ft_chrcat(lne->seg.rdr.arg.content, '\26',
			MAX_LINE_SIZE);
	else
		ft_chrcat(lne->seg.rdr.arg.content, lne->buffer[lne->index],
			MAX_LINE_SIZE);
}
