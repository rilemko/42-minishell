/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_has.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:06:36 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/25 22:01:11 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_tkn_has() :
*
*/
t_bool	ft_tkn_has(t_lst **lst, char token)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (((t_tkn *) tmp->content)->token == token)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}
