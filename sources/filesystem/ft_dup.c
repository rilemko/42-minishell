/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:34:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/18 00:31:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_dup() :
*	Duplicates the open file descriptor { file_descriptor } and returns a new
*	file descriptor, opened on the same file.
*	(i) : See ft_perror() for error on failure.
*/
t_fd	ft_dup(t_fd file_descriptor)
{
	return (dup(file_descriptor));
}
