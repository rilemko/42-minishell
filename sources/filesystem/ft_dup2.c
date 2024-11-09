/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:35:33 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/22 17:47:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_dup2() :
*	Close file descriptor { new_descriptor } if it is an open file descriptor
*	then duplicate { file_descriptor } in { new_descriptor } open on the same
*	file.
*	(i) : See ft_perror() for error on failure.
*/

t_fd	ft_dup2(t_fd file_descriptor, int new_descritptor)
{
	return (dup2(file_descriptor, new_descritptor));
}
