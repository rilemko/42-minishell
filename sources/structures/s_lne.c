/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:41:09 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/24 01:22:21 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_lne_clear(t_lne *lne)
{
	t_lst	*lst;

	lst = lne->commands;
	st_ptr_clear(&lne->ptr);
	st_seg_clear(&lne->seg);
	st_sts_clear(&lne->sts);
	while (lst)
	{
		st_cmd_clear(ft_cmd_get(&lst, 0));
		lst = lst->next;
	}
	ft_lstclear(&lne->commands, ft_free);
}

void	st_lne_initialize(t_lne *lne, t_app *app)
{
	lne->app = app;
	ft_bzero(lne->buffer, MAX_LINE_SIZE);
	lne->commands = NULL;
	lne->count = 0;
	lne->heredoc = 0;
	lne->index = -1;
	lne->is_complete = TRUE;
	lne->is_validate = TRUE;
	lne->length = 0;
	lne->read_heredoc = FALSE;
	st_ptr_initialize(&lne->ptr);
	st_seg_initialize(&lne->seg);
	st_sts_initialize(&lne->sts);
}
