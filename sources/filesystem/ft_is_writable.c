/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_writable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:10:03 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:28:47 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_is_writable() :
*	Checks if the file referred to by { pathname } is readable in
*	permission (w) if { check_file } is TRUE. Check the dirname for the same
*	permissions if { check_directory } is TRUE.
*	(i) : See ft_perror() for error on failure.
*/
t_bool	ft_is_writable(const char *pathname, t_bool check_file,
	t_bool check_directory)
{
	char	dirname[MAX_PATH_SIZE];

	ft_dirname(pathname, dirname);
	if ((check_file == FALSE || access(pathname, W_OK) != FAILURE)
		&& (check_directory == FALSE || access(dirname, W_OK) != FAILURE))
		return (TRUE);
	return (FALSE);
}
