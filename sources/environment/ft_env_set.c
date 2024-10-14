/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:17:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 16:00:31 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_env_set() :
*	Add "{ key }={ value }" to the { env } linked list as "KEY=VALUE"
*	pair. If "KEY" already exists, replace the variable with the new pair.
*/
void	ft_env_set(t_lst **env, const char *key, const char *value,
	t_bool equal)
{
	ft_env_del(env, key, ft_ternary_int(equal == TRUE, FALSE, TRUE));
	ft_env_add(env, key, value, equal);
}
