/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:14:33 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 12:22:37 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_arg_clear(t_arg *arg)
{
	st_arg_initialize(arg);
}

void	st_arg_initialize(t_arg *arg)
{
	ft_bzero(arg->content, MAX_LINE_SIZE);
	arg->in_quotes_double = FALSE;
	arg->in_quotes_simple = FALSE;
	arg->is_asterisk = FALSE;
	arg->is_variable = FALSE;
}
