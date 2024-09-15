/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:42:12 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/08 00:29:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_open() :
*	Open and return the file descriptor corresponding to { pathname }, opened
*	with flags { flags }.
*	(i) : See ft_perror() for error on failure.
*/
t_fd	ft_open(const char *pathname, int flags)
{
	return (open(pathname, flags, 0755));
}
