/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itp_process_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:44:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 18:05:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(t_app *app, t_lst *lst);

/*
*	ft_itp_process_var() :
*
*/
void	ft_itp_process_var(t_cmd *cmd, t_app *app)
{
	t_lst	*lst;

	if (cmd->has_command == FALSE)
	{
		lst = cmd->tpl.variable;
		while (lst)
		{
			ft_process(app, lst);
			lst = lst->next;
		}
	}
}

static void	ft_process(t_app *app, t_lst *lst)
{
	char	name[MAX_LINE_SIZE];
	char	body[MAX_LINE_SIZE];
	int		index;
	t_arg	*arg;
	t_arg	tmp;

	arg = ft_arg_get(&lst, 0);
	ft_bzero(name, MAX_LINE_SIZE);
	ft_bzero(body, MAX_LINE_SIZE);
	index = -1;
	st_arg_initialize(&tmp);
	tmp.in_quotes_double = arg->in_quotes_double;
	while (arg->content[++index] && arg->content[index] != TOKEN_061)
		ft_chrcat(tmp.content, arg->content[index], MAX_LINE_SIZE);
	ft_interpret_variable(&tmp, name, app, FALSE);
	st_arg_initialize(&tmp);
	tmp.in_quotes_double = arg->in_quotes_double;
	while (arg->content[++index])
		ft_chrcat(tmp.content, arg->content[index], MAX_LINE_SIZE);
	ft_interpret_variable(&tmp, body, app, FALSE);
	if (ft_env_has(&app->env, name, TRUE) || ft_env_has(&app->env, name, FALSE))
		ft_env_set(&app->env, name, body, TRUE);
	else
		ft_var_set(&app->var, name, body);
	st_arg_clear(&tmp);
}
