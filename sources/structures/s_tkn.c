/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tkn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:01:23 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/26 15:58:06 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_tkn_clear(t_tkn *tkn)
{
	(void) tkn;
}

void	st_tkn_initialize(t_tkn *tkn)
{
	ft_bzero(tkn->display, MAX_TOKN_SIZE);
	tkn->process = NULL;
	tkn->repeat_max = 1;
	tkn->token = TOKEN_000;
}
