/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:48:20 by vpolojie          #+#    #+#             */
/*   Updated: 2024/03/25 14:37:02 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset_no_opt(t_cmd *cmd)
{
	if (cmd->has_options == TRUE && cmd->has_argument == FALSE)
	{
		ft_perror("minishell", "unset", "", "no options allowed");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_unset(t_cmd *cmd, t_app *app, char *arg)
{
	char	**args;
	int		i;

	if (ft_unset_no_opt(cmd) == FAILURE)
		return (2);
	args = ft_split(arg, ' ');
	i = 0;
	while (args[i] != 0)
	{
		ft_env_del(&app->env, args[i], TRUE);
		ft_env_del(&app->env, args[i], FALSE);
		ft_var_del(&app->var, args[i]);
		i++;
	}
	ft_free_deep((void **)args);
	if (cmd->has_options == TRUE)
	{
		ft_perror(app->name, cmd->basename, "", "no options allowed");
		return (1);
	}
	return (0);
}
