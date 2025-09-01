/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:16 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:30:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_exists() :
*	Check if the file referred to by { pathname } is accessible and exists in
*	filesystem.
*	(i) : See ft_perror() for error on failure.
*/
t_bool	ft_exists(const char *pathname, t_bool check_file,
	t_bool check_directory)
{
	char	dirname[MAX_PATH_SIZE];

	ft_dirname(pathname, dirname);
	if ((check_file == FALSE || access(pathname, F_OK) != FAILURE)
		&& (check_directory == FALSE || access(dirname, F_OK) != FAILURE))
		return (TRUE);
	return (FALSE);
}
