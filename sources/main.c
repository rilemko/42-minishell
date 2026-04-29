/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:53:09 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/24 13:20:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_app	*g_minishell;

static void	ft_process(t_app *app);
static t_rt	ft_handle(t_app *app, t_lne *lne);
static t_rt	ft_capture(t_app *app, t_lne *lne);

/*
*	main() :
*	Application entry point
*	Initialize the main structure and run the main process.
*/
int	main(int argc, char **argv, char **envp)
{
	t_app			app;

	st_app_initialize(&app, argc, argv, envp);
	ft_process(&app);
	ft_exit(&app, app.last_status, "exit\n");
}

static void	ft_process(t_app *app)
{
	while (app->sts.is_running == TRUE)
	{
		st_sts_initialize(&app->sts);
		st_lne_initialize(&app->lne, app);
		if (ft_handle(app, &app->lne) == SUCCESS
			&& app->sts.is_xcuting == TRUE)
		{
			st_exe_initialize(&app->exe);
			ft_signal(SIGNAL_MODE_RUNTIME);
			ft_dup2(app->fds.fileno_std_i, STDIN_FILENO);
			tcsetattr(STDIN_FILENO, TCSANOW, &app->tio.termios_rtm);
			ft_execute(app, &app->exe, app->lne.commands, 0);
		}
		ft_history_add(app->lne.buffer, app->file_history);
		st_lne_clear(&app->lne);
	}
}

static t_rt	ft_handle(t_app *app, t_lne *lne)
{
	ft_signal(SIGNAL_MODE_DEFAULT);
	ft_app_set_prompt(app, app->cfg.rdl.prompt_default);
	while (app->sts.is_running == TRUE && app->sts.is_reading == TRUE
		&& lne->is_validate == TRUE)
	{
		ft_dup2(app->fds.fileno_std_i, STDIN_FILENO);
		tcsetattr(STDIN_FILENO, TCSANOW, &app->tio.termios_new);
		if (ft_capture(app, lne) == SUCCESS)
			return (SUCCESS);
		ft_signal(SIGNAL_MODE_CONCATE);
		ft_app_set_prompt(app, app->cfg.rdl.prompt_concate);
	}
	return (FAILURE);
}

static t_rt	ft_capture(t_app *app, t_lne *lne)
{
	if (ft_readline(app->current_prompt, &lne->buffer[lne->length])
		== FAILURE && app->sts.is_reading == TRUE)
	{
		if (lne->length == 0)
			ft_exit(app, app->last_status, "exit\n");
		if (lne->ptr.current_depth == 0 && lne->ptr.in_quotes == FALSE)
			return (ft_abort_doc(app, lne));
		if (lne->seg.rdr.read_heredoc == FALSE)
			return (ft_abort_cct(app, lne));
	}
	else if (ft_parse(app, lne) == SUCCESS)
	{
		if (lne->is_complete == TRUE)
		{
			if (app->lne.length == 0)
				ft_app_set_status(app, 0);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}
