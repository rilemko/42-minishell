/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:02:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/13 23:38:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_write() :
*	Write entirely { content } on the file descriptor { file_descriptor }.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_write(t_fd file_descriptor, const char *content)
{
	if (content != NULL && ft_strlen(content) > 0)
		if (write(file_descriptor, content, ft_strlen(content)) != FAILURE)
			return (SUCCESS);
	return (FAILURE);
}
