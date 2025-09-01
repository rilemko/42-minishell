/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_app.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:30:54 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 18:07:21 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_app_creation(t_app *app, char **envp);

void	st_app_clear(t_app *app)
{
	ft_history_clear("");
	ft_lstclear(&app->env, ft_free);
	ft_lstclear(&app->var, ft_free);
	ft_free((void *) app->name);
	ft_free((void *) app->file_history);
	ft_free((void *) app->shell);
	st_tio_clear(&app->tio);
	st_fds_clear(&app->fds);
	st_cfg_clear(&app->cfg);
}

void	st_app_initialize(t_app *app, int argc, char **argv, char **envp)
{
	g_minishell = app;
	app->argc = argc;
	ft_bzero(app->current_prompt, MAX_LINE_SIZE);
	ft_bzero(app->dir_base, MAX_PATH_SIZE);
	ft_bzero(app->dir_home, MAX_PATH_SIZE);
	ft_bzero(app->dir_root, MAX_PATH_SIZE);
	app->env = NULL;
	app->file_history = NULL;
	app->last_status = 0;
	app->name = ft_strdup(&argv[0][2]);
	app->shell = NULL;
	app->shell_level = 1;
	app->var = NULL;
	st_cfg_initialize(&app->cfg);
	st_fds_initialize(&app->fds, app);
	st_sts_initialize(&app->sts);
	st_tio_initialize(&app->tio);
	st_app_creation(app, envp);
}

static void	st_app_creation(t_app *app, char **envp)
{
	char	*current_level;

	ft_lstfromarr(&app->env, envp);
	if (ft_getcwd(app->dir_root) && ft_chdir(app->dir_root, NULL))
	{
		app->shell = ft_strmjoin(ft_strjoin(app->dir_root, "/"), app->name);
		if (ft_strcmp(ft_env_get(&app->env, "SHELL", ""), app->shell) == 0)
			app->shell_level = ft_atoi(ft_env_get(&app->env, "SHLVL", "0")) + 1;
		app->file_history = ft_strmjoin(ft_strjoin(app->dir_root, "/"),
				app->cfg.file_history);
		ft_env_set(&app->env, "OLDPWD", "", FALSE);
		ft_env_set(&app->env, "PWD", app->dir_root, TRUE);
		ft_env_set(&app->env, "SHELL", app->shell, TRUE);
	}
	ft_strlcpy(app->dir_home, ft_env_get(&app->env, "HOME", ""), MAX_PATH_SIZE);
	current_level = ft_itoa(app->shell_level);
	ft_env_set(&app->env, "SHLVL", current_level, TRUE);
	ft_free((void *) current_level);
	ft_history_load(app->file_history, TRUE);
}
