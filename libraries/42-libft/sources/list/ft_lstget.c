/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:52:45 by mconreau          #+#    #+#             */
/*   Updated: 2022/10/10 16:05:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstget(t_lst *lst, size_t index)
{
	int	cursor;

	if (!lst || index >= ft_lstsize(lst))
		return (NULL);
	cursor = -1;
	while (++cursor < (int) index)
	{
		lst = lst->next;
		if (!lst)
			return (NULL);
	}
	return (lst);
}
