/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:17:57 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/11 21:31:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_chdir() :
*	Change the current working directory to the new { pathname } and write its
*	absolute pathname in { buffer }. Make sure { buffer } is long enough.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_chdir(const char *pathname, char *buffer)
{
	if (chdir(pathname) == 0)
	{
		if (buffer != NULL)
			ft_getcwd(buffer);
		return (SUCCESS);
	}
	return (FAILURE);
}
