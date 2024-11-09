/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_042.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 21:17:11 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_042() :
*	Parsing process of character '*'.
*
*/
void	ft_prs_process_042(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	ft_tokenize(lne);
	ft_prs_process_default(lne);
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
		&& lne->seg.rdr.read_delimiter == FALSE
		&& lne->seg.rdr.read_heredoc == FALSE)
	{
		lne->seg.rdr.arg.is_asterisk = TRUE;
	}
}
