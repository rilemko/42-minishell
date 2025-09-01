/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_032.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 19:45:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_032() :
*	Parsing process of character ' '.
*
*/
void	ft_prs_process_032(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if (lne->buffer[lne->index - 1] != TOKEN_059
		&& lne->ptr.in_quotes == FALSE
		&& lne->ptr.in_comment == FALSE
		&& lne->seg.rdr.read_heredoc == FALSE)
		ft_parse_read(lne, TRUE);
	if ((lne->ptr.in_quotes == TRUE
			|| lne->seg.rdr.read_comment == TRUE
			|| lne->seg.rdr.read_heredoc == TRUE
			|| (lne->ptr.in_quotes == FALSE
				&& lne->buffer[lne->index + 1] != TOKEN_000
				&& lne->buffer[lne->index + 1] != TOKEN_032
				&& lne->seg.cmd.has_argument == TRUE
				&& lne->seg.rdr.read_command == FALSE
				&& lne->seg.rdr.read_delimiter == FALSE
				&& ((lne->seg.rdr.read_redirection_i == FALSE
						&& lne->seg.rdr.read_redirection_o == FALSE)
					|| lne->seg.rdr.is_started == TRUE)))
		&& lne->seg.wait_separator == FALSE)
	{
		ft_prs_process_default(lne);
	}
	ft_tokenize(lne);
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) lne;
	(void) tkn;
}

static void	ft_tokenize(t_lne *lne)
{
	(void) lne;
}
