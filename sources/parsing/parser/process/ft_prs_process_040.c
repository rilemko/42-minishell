/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_040.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 16:34:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_040() :
*	Parsing process of character '('.
*
*/
void	ft_prs_process_040(t_lne *lne, t_tkn *tkn)
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
	(void) tkn;
	if (lne->ptr.in_quotes == FALSE
		&& (lne->seg.is_started == TRUE
			|| lne->seg.rdr.read_options == TRUE
			|| (lne->seg.rdr.is_started == FALSE
				&& (lne->seg.rdr.read_redirection_i == TRUE
					|| lne->seg.rdr.read_redirection_o == TRUE))))
	{
		ft_parse_abort(lne, TRUE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	lne->is_complete = FALSE;
	lne->ptr.current_depth += 1;
	lne->seg.cmd.sub.is_start = TRUE;
}
