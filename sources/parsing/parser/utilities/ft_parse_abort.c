/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_abort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:59:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/17 16:34:07 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_parse_abort() :
*	Start stopping parsing. If { force } is TRUE, the parsing is stopped
*	immediately and the token in error is only the current token.
*/
t_rt	ft_parse_abort(t_lne *lne, t_bool force)
{
	if (force == TRUE)
	{
		ft_bzero(lne->seg.rdr.arg.content, MAX_LINE_SIZE);
		lne->is_validate = FALSE;
	}
	lne->seg.rdr.read_error = TRUE;
	return (FAILURE);
}
