/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itp_process_pfo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:44:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/17 16:53:55 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_itp_process_pfo() :
*
*/
void	ft_itp_process_pfo(t_cmd *cmd, t_app *app)
{
	char	buffer[MAX_LINE_SIZE];

	ft_bzero(buffer, MAX_LINE_SIZE);
	ft_interpret_concate(&cmd->tpl.pathname_file_o, app, buffer, TRUE);
	ft_strlcpy(cmd->rio.pathname_o, buffer, MAX_PATH_SIZE);
}
