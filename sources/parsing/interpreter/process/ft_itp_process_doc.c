/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itp_process_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:44:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/17 16:53:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_itp_process_doc() :
*
*/
void	ft_itp_process_doc(t_cmd *cmd, t_app *app)
{
	char	buffer[MAX_LINE_SIZE];

	ft_bzero(buffer, MAX_LINE_SIZE);
	ft_interpret_concate(&cmd->tpl.heredoc, app, buffer, FALSE);
	ft_strlcpy(cmd->heredoc, ft_ternary(buffer[0] == TOKEN_012, &buffer[1],
			&buffer[0]), MAX_LINE_SIZE);
}
