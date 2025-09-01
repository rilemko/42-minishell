/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:43:07 by vpolojie          #+#    #+#             */
/*   Updated: 2024/03/25 14:37:02 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_home(t_app *app)
{
	if (ft_env_has(&app->env, "HOME", TRUE) == TRUE)
	{
		ft_chdir(ft_env_get(&app->env, "HOME", ""), app->dir_base);
		ft_env_set(&app->env, "OLDPWD",
			ft_env_get(&app->env, "PWD", ""), TRUE);
		ft_env_set(&app->env, "PWD", app->dir_base, TRUE);
		return (0);
	}
	else
	{
		ft_perror("minishell", "cd", "", "home not set");
		return (1);
	}
}

int	ft_cd(t_app *app, char *arg)
{
	char	**args;

	if (ft_strlen(arg) == 0)
		return (ft_cd_home(app));
	args = ft_split(arg, ' ');
	if (ft_chdir(args[0], app->dir_base) == SUCCESS)
	{
		ft_env_set(&app->env, "OLDPWD", ft_env_get(&app->env, "PWD", ""), TRUE);
		ft_env_set(&app->env, "PWD", app->dir_base, TRUE);
		ft_free_deep((void **) args);
		return (0);
	}
	else
	{
		if (ft_exists(args[0], TRUE, FALSE) == FALSE
			|| ft_exists(args[0], FALSE, TRUE) == TRUE)
			ft_perror(app->name, "cd", args[0], "");
		ft_free_deep((void **) args);
		return (1);
	}
}
