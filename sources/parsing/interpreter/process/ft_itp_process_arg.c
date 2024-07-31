/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itp_process_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:44:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/17 16:53:32 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_itp_process_arg() :
*
*/
void	ft_itp_process_arg(t_cmd *cmd, t_app *app)
{
	char	buffer[MAX_LINE_SIZE];

	ft_bzero(buffer, MAX_LINE_SIZE);
	ft_interpret_concate(&cmd->tpl.argument, app, buffer, FALSE);
	ft_strlcpy(cmd->argument, buffer, MAX_LINE_SIZE);
}
