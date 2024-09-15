/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_has.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:40:36 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 15:21:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_var_has() :
*	Check for existence of key { var } as "KEY" in { lst } linked list as
*	format "KEY=VALUE".
*/
t_bool	ft_var_has(t_lst **var, const char *key)
{
	int	index;

	key = ft_strmjoin(ft_strtrim(key, "$= var"), "=");
	index = ft_lstgetindex(*var, (void *) key, ft_strlen(key));
	ft_free((void *) key);
	if (index == FAILURE)
		return (FALSE);
	return (TRUE);
}
