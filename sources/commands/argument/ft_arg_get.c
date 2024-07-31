/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:09:21 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:25:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_arg_get() :
*
*/
t_arg	*ft_arg_get(t_lst **lst, size_t index)
{
	return ((t_arg *) ft_lstgetcontent(*lst, index));
}
