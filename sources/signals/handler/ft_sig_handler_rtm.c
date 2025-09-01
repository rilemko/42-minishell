/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handler_rtm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/08 18:01:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sig_handle_sigi(void);
static void	ft_sig_handle_sigq(void);

/*
*	ft_sig_handler_rtm() :
*	Runtime handling process.
*/
void	ft_sig_handler_rtm(int type)
{
	if (type == SIGINT)
		ft_sig_handle_sigi();
	if (type == SIGQUIT)
		ft_sig_handle_sigq();
	ft_signal_register(&ft_sig_handler_rtm);
}

static void	ft_sig_handle_sigi(void)
{
	g_minishell->exe.exit_status = 130;
	ft_app_set_status(g_minishell, 130);
}

static void	ft_sig_handle_sigq(void)
{
	g_minishell->exe.exit_status = 131;
	ft_app_set_status(g_minishell, 131);
	ft_write(STDERR_FILENO, "Quit: 3\n");
}
