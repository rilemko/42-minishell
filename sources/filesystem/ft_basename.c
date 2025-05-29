/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:27:39 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:30:02 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_basename() :
*	Get the basename of pathname { pathname } and write it to { buffer }.
*	Make sure { buffer } is long enough.
*/
void	ft_basename(const char *pathname, char *buffer)
{
	size_t	length;

	if (pathname != NULL && buffer != NULL)
	{
		length = ft_strlen(pathname);
		ft_strlcpy(buffer, pathname, length + 1);
		if (ft_strpos(pathname, '/') != FAILURE)
		{
			if (length > 1)
			{
				if (buffer[length - 1] == '/')
					ft_bzero(&buffer[length - 1], 1);
				ft_strlcpy(buffer, ft_strrchr(buffer, '/') + 1, length);
				return ;
			}
		}
	}
}
