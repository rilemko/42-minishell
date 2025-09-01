/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:27:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/13 23:38:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_unlink() :
*	Delete the file referred to by { pathname }. If { pathname } is a link,
*	remove the link from filesystem.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_unlink(const char *pathname)
{
	if (unlink(pathname) != FAILURE)
		return (SUCCESS);
	return (FAILURE);
}
