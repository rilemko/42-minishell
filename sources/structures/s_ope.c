/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:03:55 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/12 16:14:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_ope_clear(t_ope *ope)
{
	(void) ope;
}

void	st_ope_initialize(t_ope *ope)
{
	ope->exists = FALSE;
	ope->has_operand_and = FALSE;
	ope->has_operand_or = FALSE;
}
