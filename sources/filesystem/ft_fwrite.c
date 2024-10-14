/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:10:59 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:27:19 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_fwrite() :
*	Write entirely { content } in the file referred to by { pathname }.
*	Write to end of file if { append } is TRUE. Erase file before writing
*	if { erase } is TRUE.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_fwrite(const char *pathname, const char *content, t_bool append,
	t_bool erase)
{
	t_fd	file_descriptor;
	int		flags;

	if (ft_is_writable(pathname, FALSE, TRUE) == TRUE)
	{
		flags = 0;
		flags |= ft_ternary_int(append, O_APPEND, 0);
		flags |= ft_ternary_int(erase, O_TRUNC, 0);
		file_descriptor = ft_fopen(pathname, FALSE, TRUE, flags);
		if (file_descriptor != FAILURE)
		{
			ft_write(file_descriptor, content);
			ft_close(file_descriptor);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}
