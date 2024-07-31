/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:53:17 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/24 01:22:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_dispatch(t_app *app, t_lne *lne);

/*
*	ft_parse() :
*
*/
t_rt	ft_parse(t_app *app, t_lne *lne)
{
	st_sts_initialize(&lne->sts);
	lne->length = ft_strlen(lne->buffer);
	while (++lne->index <= lne->length && lne->sts.is_reading == TRUE)
	{
		ft_parse_follow(lne);
		ft_dispatch(app, lne);
		if (lne->is_validate == FALSE)
			return (ft_parse_error(app, lne));
		if (lne->seg.is_complete == TRUE && lne->seg.is_started == TRUE
			&& lne->seg.rdr.read_heredoc == FALSE)
		{
			lne->count += 1;
			ft_cmd_add(&lne->commands, &lne->seg.cmd);
			st_seg_initialize(&lne->seg);
		}
	}
	return (SUCCESS);
}

static void	ft_dispatch(t_app *app, t_lne *lne)
{
	t_tkn	*tkn;

	tkn = ft_tkn_get(&app->cfg.tokens, lne->buffer[lne->index]);
	if (tkn != NULL)
		return ((tkn->process)(lne, tkn));
	return (ft_prs_process_default(lne));
}
