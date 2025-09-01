/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:04:02 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/30 22:13:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_arg_add() :
*
*/
void	ft_arg_add(t_lst **lst, t_arg *argument)
{
	ft_lstadd_back(lst, ft_lstnew(malloc(sizeof(t_arg))));
	ft_memcpy(ft_lstlast(*lst)->content, argument, sizeof(t_arg));
}
