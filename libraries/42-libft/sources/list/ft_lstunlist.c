/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstunlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:05:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 10:48:16 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstunlist(t_lst **lst, size_t index, void (*del)(void *))
{
	t_lst	*target;
	t_lst	*prev;

	if (!*lst || index >= ft_lstsize(*lst))
		return ;
	target = ft_lstget(*lst, index);
	if (index > 0)
	{
		prev = ft_lstget(*lst, index - 1);
		prev->next = ft_lstget(*lst, index + 1);
	}
	else
		*lst = ft_lstget(*lst, 1);
	ft_lstdelone(target, del);
}
