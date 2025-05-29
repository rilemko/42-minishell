/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:03:39 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:30:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_fread() :
*	Read the file referred to by { pathname } until the end of file (EOF)
*	and write the contents read in { buffer }. Make sure { buffer } is
*	long enough.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_fread(const char *pathname, char *buffer)
{
	t_fd	file_descriptor;

	if (ft_is_readable(pathname, TRUE, TRUE) == TRUE)
	{
		file_descriptor = ft_fopen(pathname, TRUE, FALSE, 0);
		if (file_descriptor != FAILURE)
		{
			ft_read(file_descriptor, buffer, -1, -1);
			ft_close(file_descriptor);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}
