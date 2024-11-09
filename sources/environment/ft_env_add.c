/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:17:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 13:55:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_env_add() :
*	Add "{ key }={ value }" to the { env } linked list as "KEY=VALUE"
*	pair. If "KEY" already exists in { env }, does nothing.
*	(i) : See ft_env_set() to overwrite a variable.
*/
void	ft_env_add(t_lst **env, const char *key, const char *value,
	t_bool equal)
{
	if (ft_env_has(env, key, equal) == FALSE)
	{
		key = ft_strmjoin(ft_strtrim(key, "$= "), ft_ternary(equal == TRUE,
					"=", ""));
		ft_lstadd_back(env, ft_lstnew(ft_strjoin(key, value)));
		ft_free((void *) key);
	}
}
