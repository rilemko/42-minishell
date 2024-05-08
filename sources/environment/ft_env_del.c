/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:13:04 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 16:55:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_env_del() :
*	Delete "KEY=VALUE" pair from the { env } linked list where "KEY"
*	matches { key } if it exists.
*/
void	ft_env_del(t_lst **env, const char *key, t_bool equal)
{
	int		index;

	key = ft_strmjoin(ft_strtrim(key, "$= "), ft_ternary(equal == TRUE,
				"=", ""));
	index = ft_lstgetindex(*env, (void *) key, ft_strlen(key));
	ft_free((void *) key);
	if (index != FAILURE)
		ft_lstunlist(env, index, ft_free);
}
