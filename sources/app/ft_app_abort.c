/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_abort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:31:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 17:53:07 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_app_abort() :
*
*/
t_rt	ft_app_abort(t_app *app)
{
	app->sts.is_reading = FALSE;
	app->sts.is_running = FALSE;
	app->sts.is_xcuting = FALSE;
	return (FAILURE);
}
