/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:48:56 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 11:29:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_extract(t_app *app, t_lne *lne, char *buffer);

/*
*	ft_parse_error() :
*	Displays the error message corresponding to the syntax error that
*	occurred during parsing and to the associated tokens.
*/
t_rt	ft_parse_error(t_app *app, t_lne *lne)
{
	char	buffer[MAX_LINE_SIZE];

	if (lne->seg.rdr.read_error == TRUE)
	{
		ft_app_set_status(app, 258);
		ft_bzero(buffer, MAX_LINE_SIZE);
		ft_strlcpy(buffer, "Syntax error near unexpected token '",
			MAX_LINE_SIZE);
		ft_extract(app, lne, &buffer[ft_strlen(buffer)]);
		ft_strlcat(buffer, "'", MAX_LINE_SIZE);
		ft_perror(app->name, "", "", buffer);
		st_arg_clear(&lne->seg.rdr.arg);
	}
	return (FAILURE);
}

static void	ft_extract(t_app *app, t_lne *lne, char *buffer)
{
	int		index;
	t_tkn	*tkn;

	index = -1;
	tkn = ft_tkn_get(&app->cfg.tokens, lne->seg.rdr.arg.content[0]);
	if (tkn != NULL && tkn->repeat_max != 0)
	{
		while (lne->seg.rdr.arg.content[++index] == tkn->token
			&& index < (int) tkn->repeat_max)
			ft_strlcat(buffer, tkn->display, MAX_LINE_SIZE);
	}
	else
	{
		while (!ft_tkn_has(&app->cfg.tokens, lne->seg.rdr.arg.content[++index])
			|| lne->seg.rdr.arg.content[index] == TOKEN_034
			|| lne->seg.rdr.arg.content[index] == TOKEN_039)
			ft_chrcat(buffer, lne->seg.rdr.arg.content[index], MAX_LINE_SIZE);
	}
}
