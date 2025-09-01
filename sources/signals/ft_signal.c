/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:29:58 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 12:43:29 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_signal() :
*	Registers the handling function corresponding to the given signal mode
*	{ signal_mode } as a signal handler.
*	(i) : See "_constants.h" for more details.
*/
void	ft_signal(t_mod signal_mode)
{
	if (signal_mode == SIGNAL_MODE_CONCATE)
		ft_signal_register(&ft_sig_handler_cct);
	if (signal_mode == SIGNAL_MODE_DEFAULT)
		ft_signal_register(&ft_sig_handler_def);
	if (signal_mode == SIGNAL_MODE_RUNTIME)
		ft_signal_register(&ft_sig_handler_rtm);
}

void	ft_signal_register(void (*handler)(int))
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
