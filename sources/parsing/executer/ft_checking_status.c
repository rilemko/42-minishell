/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:49:12 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:46:58 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_last_status(t_exe *exec, t_cmd *cmd)
{
	if (cmd->ope.has_operand_and == 1 && cmd->ope.has_operand_or == 0)
	{
		if (exec->exit_status >= 1)
			return (-1);
		else
			return (1);
	}
	if (cmd->ope.has_operand_or == 1 && cmd->ope.has_operand_and == 0)
	{
		if (exec->exit_status == 0)
			return (-1);
		else
			return (1);
	}
	else
		return (1);
}
