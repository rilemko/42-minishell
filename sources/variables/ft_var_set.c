/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:17:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 15:21:17 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_var_set() :
*	Add "{ key }={ value }" to the { var } linked list as "KEY=VALUE"
*	pair. If "KEY" already exists, replace the variable with the new pair.
*/
void	ft_var_set(t_lst **var, const char *key, const char *value)
{
	ft_var_del(var, key);
	ft_var_add(var, key, value);
}
