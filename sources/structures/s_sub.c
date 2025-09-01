/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:04:39 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:32:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_sub_clear(t_sub *sub)
{
	(void) sub;
}

void	st_sub_initialize(t_sub *sub)
{
	sub->climb = 0;
	sub->depth = 0;
	sub->is_ended = FALSE;
	sub->is_start = FALSE;
}
