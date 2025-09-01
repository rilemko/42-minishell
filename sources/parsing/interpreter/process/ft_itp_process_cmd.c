/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itp_process_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:44:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/22 19:44:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(t_cmd *cmd, t_app *app, char *buffer);

/*
*	ft_itp_process_cmd() :
*
*/
void	ft_itp_process_cmd(t_cmd *cmd, t_app *app)
{
	char	buffer[MAX_LINE_SIZE];
	char	*builtin;

	ft_bzero(buffer, MAX_LINE_SIZE);
	ft_interpret_concate(&cmd->tpl.fullname, app, buffer, FALSE);
	if (ft_strlen(buffer) == 0)
		return ;
	ft_strlcpy(cmd->terminal, buffer, MAX_PATH_SIZE);
	if (ft_strnstr(ft_env_get(&app->env, "PATH", ""), buffer, ft_strlen(buffer))
		&& ft_exists(buffer, TRUE, FALSE))
		cmd->exists = TRUE;
	else
		ft_process(cmd, app, buffer);
	ft_strlcpy(cmd->fullname, buffer, MAX_PATH_SIZE);
	ft_basename(cmd->fullname, cmd->basename);
	builtin = ft_strmjoin(ft_strjoin(";", cmd->basename), ";");
	cmd->is_builtins = ft_ternary_int(ft_strnstr(app->cfg.builtins,
				builtin, ft_strlen(app->cfg.builtins)) != NULL, TRUE,
			FALSE);
	ft_free((void *) builtin);
	cmd->is_readable = ft_is_readable(cmd->fullname, TRUE, FALSE);
	cmd->is_writable = ft_is_writable(cmd->fullname, TRUE, FALSE);
	cmd->is_xcutable = ft_is_xcutable(cmd->fullname, TRUE, FALSE);
	if (cmd->is_builtins == FALSE)
		ft_interpret_normalize(cmd->argument);
}

static void	ft_process(t_cmd *cmd, t_app *app, char *buffer)
{
	char	dirname[MAX_PATH_SIZE];
	char	*current;
	char	**paths;
	int		index;

	index = -1;
	paths = ft_split(ft_env_get(&app->env, "PATH", ""), TOKEN_058);
	while (paths[++index])
	{
		current = ft_strmjoin(ft_strjoin(paths[index], "/"), buffer);
		ft_dirname(current, dirname);
		if (ft_exists(current, TRUE, FALSE) == TRUE)
		{
			cmd->exists = TRUE;
			ft_strlcpy(buffer, current, MAX_LINE_SIZE);
			ft_free((void *) current);
			break ;
		}
		ft_free((void *) current);
	}
	ft_free_deep((void **) paths);
	if (ft_exists(buffer, TRUE, FALSE) == TRUE)
		cmd->exists = TRUE;
}
