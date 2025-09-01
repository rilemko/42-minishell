/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:15:13 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/17 16:59:15 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_cmd_add() :
*	
*/
void	ft_cmd_add(t_lst **lst, t_cmd *command)
{
	ft_lstadd_back(lst, ft_lstnew(malloc(sizeof(t_cmd))));
	ft_memcpy(ft_lstlast(*lst)->content, command, sizeof(t_cmd));
}
