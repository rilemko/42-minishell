/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:17:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 14:05:14 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_var_add() :
*	Add "{ key }={ value }" to the { var } linked list as "KEY=VALUE"
*	pair. If "KEY" already exists in { var }, does nothing.
*	(i) : See ft_var_set() to overwrite a variable.
*/
void	ft_var_add(t_lst **var, const char *key, const char *value)
{
	if (ft_var_has(var, key) == FALSE)
	{
		key = ft_strmjoin(ft_strtrim(key, "$= "), "=");
		ft_lstadd_back(var, ft_lstnew(ft_strjoin(key, value)));
		ft_free((void *) key);
	}
}
