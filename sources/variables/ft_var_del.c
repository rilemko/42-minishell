/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:13:04 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 15:20:47 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_var_del() :
*	Delete "KEY=VALUE" pair from the { var } linked list where "KEY"
*	matches { key } if it exists.
*/
void	ft_var_del(t_lst **var, const char *key)
{
	int		index;

	key = ft_strmjoin(ft_strtrim(key, "$= "), "=");
	index = ft_lstgetindex(*var, (void *) key, ft_strlen(key));
	ft_free((void *) key);
	if (index != FAILURE)
		ft_lstunlist(var, index, ft_free);
}
