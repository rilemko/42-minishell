/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:36:45 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/26 19:09:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_parse_follow() :
*	Calculates the uninterrupted repetition of the current token.
*/
void	ft_parse_follow(t_lne *lne)
{
	if (lne->buffer[lne->index] == lne->buffer[lne->index - 1]
		&& lne->index > 0)
		lne->ptr.following += 1;
	else
		lne->ptr.following = 1;
}
