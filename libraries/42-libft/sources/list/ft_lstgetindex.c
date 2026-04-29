/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:12:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/17 23:51:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstgetindex(t_lst *lst, void *content, size_t size)
{
	int	index;

	if (!lst)
		return (-1);
	index = 0;
	while (lst)
	{
		if (!ft_memcmp(content, lst->content, size))
			return (index);
		lst = lst->next;
		index++;
	}
	return (-1);
}
