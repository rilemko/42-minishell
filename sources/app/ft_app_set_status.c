/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_set_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:41:58 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/14 16:05:47 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_app_set_status() :
*	Applies the new last status { status } to application { app }.
*/
void	ft_app_set_status(t_app *app, int status)
{
	app->last_status = status;
}
