/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:44:02 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:26:43 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_dirname() :
*	Get the dirname of pathname { pathname } and write it to { buffer }.
*	Make sure { buffer } is long enough.
*/
void	ft_dirname(const char *pathname, char *buffer)
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
				if (ft_strrchr(buffer, '/') == buffer)
					ft_bzero(&buffer[1], 1);
				if (ft_strrchr(buffer, '/') > buffer)
					ft_bzero(ft_strrchr(buffer, '/'), 1);
			}
			return ;
		}
		ft_strlcpy(buffer, ".", 2);
	}
}
