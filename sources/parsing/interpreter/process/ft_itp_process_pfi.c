/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itp_process_pfi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:44:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/17 16:53:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_itp_process_pfi() :
*
*/
void	ft_itp_process_pfi(t_cmd *cmd, t_app *app)
{
	char	buffer[MAX_LINE_SIZE];

	ft_bzero(buffer, MAX_LINE_SIZE);
	ft_interpret_concate(&cmd->tpl.pathname_file_i, app, buffer, TRUE);
	ft_strlcpy(cmd->rio.pathname_i, buffer, MAX_PATH_SIZE);
}
