/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:33:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/13 23:38:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_close() :
*	Close the file descriptor pointed to by { file_descriptor }.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_close(t_fd file_descriptor)
{
	if (close(file_descriptor) == 0)
		return (SUCCESS);
	return (FAILURE);
}
