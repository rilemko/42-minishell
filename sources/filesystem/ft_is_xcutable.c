/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_xcutable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:10:03 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:28:55 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_is_xcutable() :
*	Checks if the file referred to by { pathname } is readable in
*	permission (x) if { check_file } is TRUE. Check the dirname for the same
*	permissions if { check_directory } is TRUE.
*	(i) : See ft_perror() for error on failure.
*/
t_bool	ft_is_xcutable(const char *pathname, t_bool check_file,
	t_bool check_directory)
{
	char	dirname[MAX_PATH_SIZE];

	ft_dirname(pathname, dirname);
	if ((check_file == FALSE || access(pathname, X_OK) != FAILURE)
		&& (check_directory == FALSE || access(dirname, X_OK) != FAILURE))
		return (TRUE);
	return (FALSE);
}
