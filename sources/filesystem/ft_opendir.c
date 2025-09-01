/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:19:57 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:29:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_opendir() :
*	Open and return a pointer to the directory stream referred to by { pathname }.
*	(i) : See ft_perror() for error on failure.
*/
t_ds	*ft_opendir(const char *pathname)
{
	return (opendir(pathname));
}
