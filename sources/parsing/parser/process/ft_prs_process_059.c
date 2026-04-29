/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_059.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 21:17:28 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_059() :
*	Parsing process of character ';'.
*
*/
void	ft_prs_process_059(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	if (lne->buffer[lne->index - 1] != TOKEN_032
		&& lne->buffer[lne->index - 1] != TOKEN_039
		&& lne->buffer[lne->index - 1] != TOKEN_034
		&& lne->ptr.in_comment == FALSE)
		ft_parse_read(lne, lne->ptr.in_quotes == FALSE);
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
		&& ((lne->ptr.current_depth == 0 && lne->seg.is_started == FALSE)
			|| lne->ptr.following > tkn->repeat_max))
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->seg.is_started == TRUE)
		lne->seg.is_complete = TRUE;
	lne->seg.wait_separator = FALSE;
}
