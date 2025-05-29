/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:36 by vpolojie          #+#    #+#             */
/*   Updated: 2024/03/30 16:05:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_builtin(t_cmd *cmd, char **env)
{
	int	i;

	i = 0;
	if (cmd->has_argument == TRUE || cmd->has_options == TRUE)
	{
		cmd->builtin_status = FALSE;
		ft_free_deep((void **) env);
		ft_perror("minishell", cmd->basename, "",
			"no argument or options allowed");
		return (1);
	}
	while (env[i] != 0)
	{
		if (ft_strpos(env[i], '=') == -1)
			i++;
		else
		{
			ft_write(STDOUT_FILENO, env[i]);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	ft_free_deep((void **) env);
	return (0);
}
