/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_036.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/24 01:21:55 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_precheck(t_lne *lne, t_tkn *tkn);
static void	ft_tokenize(t_lne *lne);

/*
*	ft_prs_process_036() :
*	Parsing process of character '$'.
*
*/
void	ft_prs_process_036(t_lne *lne, t_tkn *tkn)
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
	if ((ft_isalpha(lne->buffer[lne->index + 1]) == TRUE
			|| lne->buffer[lne->index + 1] == TOKEN_063)
		&& lne->ptr.in_quotes_simple == FALSE
		&& lne->seg.rdr.read_comment == FALSE
		&& lne->seg.rdr.read_delimiter == FALSE
		&& lne->seg.rdr.read_variable == FALSE)
	{
		if (lne->ptr.in_quotes_double == FALSE)
			ft_parse_read(lne, lne->seg.rdr.read_command == FALSE
				&& (lne->ptr.in_quotes == FALSE
					|| (lne->seg.rdr.read_options == FALSE
						&& lne->seg.rdr.read_redirection_i == FALSE
						&& lne->seg.rdr.read_redirection_o == FALSE)));
		lne->seg.rdr.arg.is_variable = TRUE;
	}
}
