/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/14 22:17:41 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_prs_reading_err() :
*
*/
void	ft_prs_reading_err(t_lne *lne, t_bool cut)
{
	if (cut == TRUE)
	{
		lne->is_validate = FALSE;
		lne->sts.is_reading = FALSE;
	}
}
