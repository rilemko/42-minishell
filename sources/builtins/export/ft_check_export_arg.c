/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_export_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:15:25 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/18 18:30:23 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if ((!ft_isdigit(arg[i])) && ft_isalpha(arg[i]))
		i++;
	else
		return (FAILURE);
	while (arg[i] != '\0')
	{
		if (arg[i] == '=')
			break ;
		if (ft_isdigit(arg[i]) || ft_isalpha(arg[i]))
			i++;
		else
			return (FAILURE);
	}
	return (SUCCESS);
}
