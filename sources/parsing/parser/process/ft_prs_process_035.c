/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_035.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 21:16:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_035() :
*	Parsing process of character '#'.
*
*/
void	ft_prs_process_035(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if (lne->index > 0 && ((lne->buffer[lne->index - 1] != TOKEN_032
				&& lne->ptr.in_quotes == FALSE)
			|| lne->ptr.in_quotes == TRUE
			|| lne->seg.rdr.read_comment == TRUE
			|| lne->seg.rdr.read_error == TRUE
			|| lne->seg.rdr.read_heredoc == TRUE))
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
	lne->ptr.in_comment = TRUE;
	lne->seg.rdr.read_command = FALSE;
	lne->seg.rdr.read_comment = TRUE;
	lne->seg.rdr.read_delimiter = FALSE;
	lne->seg.rdr.read_herestr = FALSE;
	lne->seg.rdr.read_options = FALSE;
	lne->seg.rdr.read_redirection_i = FALSE;
	lne->seg.rdr.read_redirection_o = FALSE;
}
