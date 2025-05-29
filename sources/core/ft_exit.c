/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:01:17 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 17:31:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_exit() :
*	Write { message } to STDOUT_FILENO and exit the current process with the
*	exit code { exit_code }.
*/
void	ft_exit(t_app *app, int exit_code, const char *message)
{
	st_app_clear(app);
	ft_write(STDOUT_FILENO, message);
	exit(exit_code);
}

/*
*	ft_exit_failure() :
*	Write { message } to STDERR_FILENO and exit the current process with the
*	exit code EXIT_FAILURE (1).
*/
void	ft_exit_failure(t_app *app, const char *message)
{
	ft_write(STDERR_FILENO, message);
	ft_exit(app, EXIT_FAILURE, "");
}

/*
*	ft_exit_success() :
*	Write { message } to STDOUT_FILENO and exit the current process with the
*	exit code EXIT_SUCCESS (0).
*/
void	ft_exit_success(t_app *app, const char *message)
{
	ft_write(STDOUT_FILENO, message);
	ft_exit(app, EXIT_SUCCESS, "");
}
