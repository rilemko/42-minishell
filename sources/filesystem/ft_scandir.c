/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scandir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:28:57 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:29:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_scandir() :
*	Writes in the array { names } the list of entries present in the
*	directory targeted by { pathname }, respecting the filter { filter } and
*	sorted using ft_qsort() with { compare } function.
*	(!) : This function allocates memory in { names }, which must be free.
*/
size_t	ft_scandir(const char *pathname, char ***names,
	t_rt (*filter)(struct dirent *), int (*compare)(void *, void *))
{
	t_ds			*stream;
	struct dirent	current_node;
	char			*buffer;
	size_t			count;

	count = 0;
	buffer = ft_strdup("");
	if (buffer != NULL && pathname != NULL && ft_strlen(pathname) > 0)
	{
		stream = ft_opendir(pathname);
		if (stream != NULL)
		{
			while (ft_readdir(stream, &current_node) == SUCCESS && ++count)
				if ((*filter) == NULL || (*filter)(&current_node) != FAILURE)
					buffer = ft_strmjoin(
							ft_strmjoin(buffer, " "), current_node.d_name);
			*(names) = ft_split(buffer, ' ');
			ft_qsort((void **) *(names), (*compare), count);
			ft_closedir(stream);
		}
	}
	ft_free((void *) buffer);
	return (count);
}
