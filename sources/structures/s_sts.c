/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:06:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/03 15:26:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_sts_clear(t_sts *sts)
{
	(void) sts;
}

void	st_sts_initialize(t_sts *sts)
{
	sts->is_reading = TRUE;
	sts->is_running = TRUE;
	sts->is_xcuting = TRUE;
}
