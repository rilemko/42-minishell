/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetcontent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:09:38 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/17 23:51:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstgetcontent(t_lst *lst, size_t index)
{
	int	cursor;

	if (!lst)
		return (NULL);
	cursor = -1;
	while (++cursor < (int) index)
	{
		lst = lst->next;
		if (!lst)
			return (NULL);
	}
	return (lst->content);
}
