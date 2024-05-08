/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handler_def.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:39 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 22:23:56 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sig_handle_sigi(void);
static void	ft_sig_handle_sigq(void);

/*
*	ft_sig_handler_def() :
*	Default handling process.
*/
void	ft_sig_handler_def(int type)
{
	if (type == SIGINT)
		ft_sig_handle_sigi();
	if (type == SIGQUIT)
		ft_sig_handle_sigq();
	ft_signal_register(&ft_sig_handler_def);
}

static void	ft_sig_handle_sigi(void)
{
	ft_app_set_status(g_minishell, 1);
	ft_readline_nl("");
}

static void	ft_sig_handle_sigq(void)
{
}
