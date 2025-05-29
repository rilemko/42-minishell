/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort_cct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:05:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/22 00:12:59 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_abort_cct() :
*
*/
t_rt	ft_abort_cct(t_app *app, t_lne *lne)
{
	char	buffer[MAX_LINE_SIZE];

	app->sts.is_reading = FALSE;
	ft_bzero(buffer, MAX_LINE_SIZE);
	ft_strlcat(buffer, "unexpected EOF while looking for matching '",
		MAX_LINE_SIZE);
	ft_strlcat(buffer, ft_ternary(lne->ptr.in_quotes_double == TRUE,
			"\"", ft_ternary(lne->ptr.in_quotes_simple == TRUE, "'",
				ft_ternary(lne->ptr.current_depth > 0, ")", " "))),
		MAX_LINE_SIZE);
	ft_strlcat(buffer, "'",
		MAX_LINE_SIZE);
	ft_perror(app->name, "", "", buffer);
	ft_perror(app->name, "syntax error", "", "unexpected end-of-file");
	return (FAILURE);
}
