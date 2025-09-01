/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:00:39 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/21 17:29:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_env_get() :
*	Get the VALUE part from the "KEY=VALUE" pair where "KEY"
*	matches { key } in the { env } linked list. Returns { default_value } if
*	it does not exist
*/
char	*ft_env_get(t_lst **env, const char *key, const char *def_value)
{
	int		index;

	key = ft_strmjoin(ft_strtrim(key, "$= "), "=");
	index = ft_lstgetindex(*env, (void *) key, ft_strlen(key));
	ft_free((void *) key);
	if (index != FAILURE)
		return (ft_strchr(ft_lstgetcontent(*env, index), '=') + 1);
	return ((char *) def_value);
}
