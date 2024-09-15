/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_concate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:01:08 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 12:30:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(t_app *app, t_arg *arg, char *buffer, t_bool preserve);

/*
*	ft_interpret_concate() :
*	
*/
void	ft_interpret_concate(t_lst **lst, t_app *app, char *buffer,
	t_bool preserve)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_process(app, ft_arg_get(&tmp, 0), buffer, preserve);
		tmp = tmp->next;
	}
}

static void	ft_process(t_app *app, t_arg *arg, char *buffer, t_bool preserve)
{
	if (arg->is_asterisk == TRUE)
		return (ft_interpret_asterisk(arg, buffer));
	if (arg->is_variable == TRUE)
		return (ft_interpret_variable(arg, buffer, app, preserve));
	ft_strlcat(buffer, arg->content, MAX_LINE_SIZE);
}
