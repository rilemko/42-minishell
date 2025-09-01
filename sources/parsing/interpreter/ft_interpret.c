/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:16 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 22:38:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_interpret() :
*	Interprets the dynamic data set of the command { cmd } and replaces them
*	with the corresponding values.
*/
void	ft_interpret(t_app *app, t_cmd *cmd)
{
	ft_itp_process_var(cmd, app);
	ft_itp_process_cmd(cmd, app);
	ft_itp_process_arg(cmd, app);
	ft_itp_process_doc(cmd, app);
	ft_itp_process_opt(cmd, app);
	ft_itp_process_pfi(cmd, app);
	ft_itp_process_pfo(cmd, app);
}
