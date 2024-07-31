/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:08:12 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/11 21:31:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_getcwd() :
*	Find the current working directory and write its absolute pathname in 
*	{ buffer }. Make sure { buffer } is long enough.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_getcwd(char *buffer)
{
	char	*directory;

	directory = getcwd(NULL, 0);
	if (directory != NULL)
	{
		if (buffer != NULL)
			ft_strlcpy(buffer, directory, ft_strlen(directory) + 1);
		ft_free((void *) directory);
		return (SUCCESS);
	}
	return (FAILURE);
}
