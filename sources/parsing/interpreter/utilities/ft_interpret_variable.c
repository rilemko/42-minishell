/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:55:56 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/24 01:21:58 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_format(char *buffer);
static void	ft_process(const char *content, char *buffer, t_app *app,
				t_bool preserve);
/*
*	ft_interpret_variable() :
*	
*/

void	ft_interpret_variable(t_arg *arg, char *buffer, t_app *app,
	t_bool preserve)
{
	char	name[MAX_LINE_SIZE];
	int		index;

	index = 0;
	while (arg->content[index])
	{
		if (arg->content[index] == TOKEN_036
			|| arg->content[index] == TOKEN_176)
		{
			ft_bzero(name, MAX_LINE_SIZE);
			ft_chrcat(name, arg->content[index++], MAX_LINE_SIZE);
			while (arg->content[index] && arg->content[index] != TOKEN_012
				&& (ft_isspace(arg->content[index]) == FALSE)
				&& (ft_isalnum(arg->content[index])
					|| arg->content[index] == TOKEN_063)
				&& arg->content[index - 1] != TOKEN_063
				&& arg->content[index - 1] != TOKEN_176)
				ft_chrcat(name, arg->content[index++], MAX_LINE_SIZE);
			ft_process(name, buffer, app, preserve);
		}
		else
			ft_chrcat(buffer, arg->content[index++], MAX_LINE_SIZE);
	}
	if (arg->in_quotes_double == FALSE)
		ft_format(buffer);
}

static void	ft_process(const char *content, char *buffer, t_app *app,
	t_bool preserve)
{
	char	*status;

	if (ft_strlen(content) == 2 && content[1] == TOKEN_063)
	{
		status = ft_itoa(app->last_status);
		ft_strlcat(buffer, status, MAX_LINE_SIZE);
		ft_free((void *) status);
	}
	else if (ft_strlen(content) == 1 && content[0] == TOKEN_176)
		ft_strlcat(buffer, app->dir_home, MAX_LINE_SIZE);
	else
	{
		ft_strlcat(buffer, ft_env_get(&app->env, content,
				ft_var_get(&app->var, content, ft_ternary(preserve == TRUE,
						(char *) content, ""))), MAX_LINE_SIZE);
	}
}

static void	ft_format(char *content)
{
	char	buffer[MAX_LINE_SIZE];
	int		index;

	index = -1;
	ft_bzero(buffer, MAX_LINE_SIZE);
	while (content[++index])
	{
		if (content[index] == TOKEN_009 || content[index] == TOKEN_032)
		{
			if (content[index - 1] != TOKEN_009
				&& content[index - 1] != TOKEN_032)
				ft_chrcat(buffer, TOKEN_032, MAX_LINE_SIZE);
		}
		else
			ft_chrcat(buffer, content[index], MAX_LINE_SIZE);
	}
	ft_strlcpy(content, buffer, MAX_LINE_SIZE);
}
