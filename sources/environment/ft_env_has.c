/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_has.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:40:36 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 16:30:39 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_env_has() :
*	Check for existence of key { env } as "KEY" in { lst } linked list as
*	format "KEY=VALUE".
*/
t_bool	ft_env_has(t_lst **env, const char *key, t_bool equal)
{
	int	index;

	key = ft_strmjoin(ft_strtrim(key, "$= "), ft_ternary(equal == TRUE,
				"=", ""));
	index = ft_lstgetindex(*env, (void *) key, ft_strlen(key));
	ft_free((void *) key);
	if (index == FAILURE)
		return (FALSE);
	return (TRUE);
}
