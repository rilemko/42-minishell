/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_061.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 21:18:04 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_060() :
*	Parsing process of character '='.
*
*/
void	ft_prs_process_061(t_lne *lne, t_tkn *tkn)
{
	ft_precheck(lne, tkn);
	ft_prs_process_default(lne);
	ft_tokenize(lne);
}

static void	ft_precheck(t_lne *lne, t_tkn *tkn)
{
	(void) tkn;
	if (lne->ptr.in_quotes == FALSE
		&& lne->seg.wait_separator == TRUE)
	{
		ft_parse_abort(lne, FALSE);
	}
}

static void	ft_tokenize(t_lne *lne)
{
	if (lne->ptr.in_quotes == FALSE
		&& lne->seg.cmd.has_command == FALSE
		&& lne->seg.rdr.read_comment == FALSE
		&& lne->seg.rdr.read_delimiter == FALSE
		&& lne->seg.rdr.read_error == FALSE
		&& lne->seg.rdr.read_herestr == FALSE
		&& lne->seg.rdr.read_options == FALSE
		&& lne->seg.rdr.read_redirection_i == FALSE
		&& lne->seg.rdr.read_redirection_o == FALSE)
		lne->seg.rdr.read_variable = TRUE;
}
