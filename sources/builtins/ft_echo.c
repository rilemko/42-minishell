/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:14:38 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:39:45 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_opt_parsing(char *opt)
{
	int	i;

	i = -1;
	if (ft_strlen(opt) == 0)
		return (FALSE);
	while (opt[++i] == '-')
		continue ;
	while (opt[i] != '\0')
	{
		if (opt[i] == 'n' || opt[i] == 'e')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	ft_echo(t_cmd *cmd, char *arg, char *opt)
{
	(void)cmd;
	if (arg != NULL)
	{
		if (ft_strlen(opt) > 0 && opt[0] != TOKEN_032
			&& ft_opt_parsing(opt) == FALSE)
		{
			ft_write(STDOUT_FILENO, opt);
		}
		ft_write(STDOUT_FILENO, arg);
		if (ft_strlen(opt) > 0 && opt[0] == TOKEN_032)
		{
			ft_write(STDOUT_FILENO, opt);
		}
	}
	if (ft_strlen(opt) == 0 || opt[0] == TOKEN_032
		|| ft_strpos(opt, 'n') == FAILURE)
		ft_write(STDOUT_FILENO, "\n");
	return (0);
}
