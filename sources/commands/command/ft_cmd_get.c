/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:21:58 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/30 22:13:30 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_cmd_get() :
*	
*/
t_cmd	*ft_cmd_get(t_lst **lst, size_t index)
{
	return ((t_cmd *) ft_lstgetcontent(*lst, index));
}
