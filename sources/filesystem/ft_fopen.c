/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:04:15 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/08 00:29:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_fopen() :
*	Open and return the file descriptor corresponding to { pathname }
*	opened with flags { flags }. It is opened for writing if { read } is TRUE
*	and for writing if { write } is TRUE. If the file is opened for writing
*	and does not exist, it is created.
*	(i) : See ft_perror() for error on failure.
*/
t_fd	ft_fopen(const char *pathname, t_bool read, t_bool write, int flags)
{
	if ((read == FALSE || ft_is_readable(pathname, FALSE, TRUE) == TRUE)
		|| (write == FALSE || ft_is_writable(pathname, FALSE, FALSE) == TRUE))
	{
		flags |= ft_ternary_int(read, O_RDONLY, 0);
		flags |= ft_ternary_int(write, O_CREAT | O_WRONLY, 0);
		return (ft_open(pathname, flags));
	}
	return (FAILURE);
}
