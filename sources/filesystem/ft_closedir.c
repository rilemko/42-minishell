/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closedir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:28:04 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:26:56 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_closedir() :
*	Close the directory stream referred to by { stream }.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_closedir(t_ds *stream)
{
	if (closedir(stream) != FAILURE)
		return (SUCCESS);
	return (FAILURE);
}
