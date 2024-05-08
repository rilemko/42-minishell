/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:48:18 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/08 00:29:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_size() :
*	Return the size of the file referred to by { pathname } in bytes.
*	(i) : See ft_perror() for error on failure.
*/
t_bytes	ft_size(const char *pathname)
{
	struct stat	file;

	if (stat(pathname, &file) != FAILURE)
		return (file.st_size);
	return (FAILURE);
}
