/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handler_cct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/08 18:01:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sig_handle_sigi(void);
static void	ft_sig_handle_sigq(void);

/*
*	ft_sig_handler_cct() :
*	Concate handling process.
*/
void	ft_sig_handler_cct(int type)
{
	if (type == SIGINT)
		ft_sig_handle_sigi();
	if (type == SIGQUIT)
		ft_sig_handle_sigq();
	ft_signal_register(&ft_sig_handler_cct);
}

static void	ft_sig_handle_sigi(void)
{
	ft_app_set_status(g_minishell, 1);
	g_minishell->lne.is_validate = FALSE;
	g_minishell->sts.is_reading = FALSE;
	ft_readline_sl("\n");
	ft_close(STDIN_FILENO);
}

static void	ft_sig_handle_sigq(void)
{
}
