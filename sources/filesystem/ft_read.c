/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:18:24 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/23 18:00:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_read() :
*	Read on file descriptor { file_descriptor } until encountering the
*	character { delimiter } if specidfied (> -1), up to the nth character if
*	size is specified (> 0), or up to end of file (EOF) and writes the
*	characters read into { buffer }. Make sure { buffer } is long enough.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_read(t_fd file_descriptor, char *buffer, char delimiter, int size)
{
	char	character;
	t_bytes	bytes;

	while (size-- != 0)
	{
		bytes = read(file_descriptor, &character, 1);
		if (bytes == -1)
			return (FAILURE);
		if (bytes == 0 || (ft_isprint(delimiter) && character == delimiter))
			break ;
		ft_chrcat(buffer, character, ft_strlen(buffer) + 2);
	}
	return (SUCCESS);
}
