/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_176.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/22 23:19:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_176() :
*	Parsing process of character '~'.
*
*/
void	ft_prs_process_176(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	ft_prs_process_default(lne);
	ft_tokenize(lne);
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) lne;
	(void) tkn;
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->ptr.in_quotes == FALSE
		&& lne->seg.rdr.read_comment == FALSE
		&& lne->seg.rdr.read_error == FALSE
		&& lne->seg.rdr.read_heredoc == FALSE
		&& (lne->index == 0
			|| ft_isspace(lne->buffer[lne->index - 1]) == TRUE)
		&& (lne->buffer[lne->index + 1] == TOKEN_000
			|| ft_isspace(lne->buffer[lne->index + 1]) == TRUE))
		lne->seg.rdr.arg.is_variable = TRUE;
}
