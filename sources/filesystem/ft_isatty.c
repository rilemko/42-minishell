/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isatty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:28:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/03 14:33:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_isatty() :
*	Checks if the file descriptor { file_descriptor } is associated with a
*	terminal.
*/
t_rt	ft_isatty(t_fd file_descriptor)
{
	if (isatty(file_descriptor) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}
