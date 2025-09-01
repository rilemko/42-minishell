/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:03:15 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:26:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_tkn_add() :
*
*/
void	ft_tkn_add(t_lst **lst, char token, void (*process)(t_lne *, t_tkn *),
	size_t repeat, const char *display)
{
	t_tkn	tkn;

	st_tkn_initialize(&tkn);
	ft_strlcpy(tkn.display, display, MAX_TOKN_SIZE);
	tkn.process = process;
	tkn.repeat_max = repeat;
	tkn.token = token;
	ft_lstadd_back(lst, ft_lstnew(malloc(sizeof(t_tkn))));
	ft_memcpy(ft_lstlast(*lst)->content, &tkn, sizeof(t_tkn));
}
