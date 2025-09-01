/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_seg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:35:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 13:35:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_seg_clear(t_seg *seg)
{
	st_cmd_clear(&seg->cmd);
	st_rdr_clear(&seg->rdr);
}

void	st_seg_initialize(t_seg *seg)
{
	seg->count = 0;
	seg->is_complete = FALSE;
	seg->is_started = FALSE;
	seg->wait_separator = FALSE;
	st_cmd_initialize(&seg->cmd);
	st_rdr_initialize(&seg->rdr);
}
