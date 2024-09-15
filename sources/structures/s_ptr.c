/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:35:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 21:19:20 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_ptr_clear(t_ptr *ptr)
{
	(void) ptr;
}

void	st_ptr_initialize(t_ptr *ptr)
{
	ptr->current_depth = 0;
	ptr->following = 1;
	ptr->in_comment = FALSE;
	ptr->in_quotes = FALSE;
	ptr->in_quotes_double = FALSE;
	ptr->in_quotes_simple = FALSE;
}
