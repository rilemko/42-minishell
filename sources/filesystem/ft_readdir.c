/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:30:36 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/13 23:38:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_readdir() :
*	Read the next node on the directory stream { stream } and write information
*	about it to { node }.
*	(?) : See struct "dirent" (directory entry) for more details.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_readdir(t_ds *stream, struct dirent *node)
{
	struct dirent	*entry;

	entry = readdir(stream);
	if (entry != NULL)
	{
		ft_memcpy(node, entry, sizeof(struct dirent));
		return (SUCCESS);
	}
	return (FAILURE);
}
