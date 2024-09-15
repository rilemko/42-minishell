/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:03:55 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 16:57:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_rio_clear(t_rio *rio)
{
	(void) rio;
}

void	st_rio_initialize(t_rio *rio)
{
	rio->exists = FALSE;
	rio->file_append = FALSE;
	rio->has_file_i = FALSE;
	rio->has_file_o = FALSE;
	rio->has_pipe_i = FALSE;
	rio->has_pipe_o = FALSE;
	ft_bzero(rio->pathname_i, MAX_PATH_SIZE);
	ft_bzero(rio->pathname_o, MAX_PATH_SIZE);
}
