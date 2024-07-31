/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_change_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:24:30 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/22 17:29:56 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_app_set_prompt() :
*	Applies the new prompt { prompt } to application { app }.
*/

void	ft_app_set_prompt(t_app *app, const char *prompt)
{
	ft_strlcpy(app->current_prompt, prompt, MAX_LINE_SIZE);
}
