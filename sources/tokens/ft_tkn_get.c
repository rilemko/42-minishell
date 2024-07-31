/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:06:36 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/23 14:41:49 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_tkn_get() :
*
*/
t_tkn	*ft_tkn_get(t_lst **lst, char token)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (((t_tkn *) tmp->content)->token == token)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
